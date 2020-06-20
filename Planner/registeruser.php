<?php
    session_start();

    function createTables(){
        $servername = "localhost";
        $username = "root";
        $password = "";
        $db = "plannerbybeni";
        $connection = new mysqli($servername, $username, $password, $db);
        $sql = "CREATE TABLE IF NOT EXISTS personcredentials(
            PersonID INT(11) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
            LastName varchar(255),
            FirstName varchar(255),
            username varchar(255),
            email varchar(255),
            pswrd varchar(255)
        )";
        if ($connection->query($sql) === TRUE) {
        } else {
            echo "Error creating table : " . $connection->error;
        }
        $sql = "CREATE TABLE IF NOT EXISTS usertodo(
            text varchar(2000) NOT NULL,
            username varchar(255) NOT NULL,
            month int(11) NOT NULL,
            day int(11) NOT NULL
        )";
        if ($connection->query($sql) === TRUE) {
        } else {
            echo "Error creating table 2 : " . $connection->error;
        }
        $connection->close();
    }

    function clearInput($data) {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $servername = "localhost";
        $username = "root";
        $password = "";

        $connection = new mysqli($servername, $username, $password);

        $sql = "CREATE DATABASE IF NOT EXISTS plannerbybeni";
        echo "WHAT IS THIS<br>";
        if ($connection->connect_error) {
            die("Connection failed: " . $connection->connect_error);
        }

        if ($connection->query($sql) === TRUE){
            createTables();
        } else {
            echo "Error creating database : " . $connection->error;
            createTables();
        }

        if(!$connection){
            echo "WHAT IS THIS<br>";
            die("Could not connect: " . $connection->connect_error);
        }
        $connection = new mysqli($servername, $username, $password, "plannerbybeni");
        $uname = clearInput($_POST['username']);
        $fname = clearInput($_POST['fname']);
        $lname = clearInput($_POST['lname']);
        $email = clearInput($_POST['email']);
        $pwd = clearInput($_POST['password']);
        $cpwd = clearInput($_POST['cpassword']);
        $emailError = '';
        if($uname != ''){
            if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
                $emailError = "Invalid email format";
                echo $emailError;
            }
            if($emailError == ''){
                if($connection->query('SELECT username FROM PersonCredentials WHERE username = $uname')){
                    echo 'Username already taken';
                }
                else if($connection->query('SELECT email FROM PersonCredentials WHERE email = $email')){
                    echo 'Email already taken';
                }
                else if($pwd == $cpwd){
                    $sql = "INSERT INTO `PersonCredentials`(FirstName, LastName, username, email, pswrd)
                                                 VALUES (?,?,?,?,?)";
                    if($stmt = $connection->prepare($sql)){
                        $stmt->bind_param("sssss",$fname,$lname,$uname,$email,$pwd);
                        $stmt->execute();
                        header("location: index.php");
                        exit;
                    }
                    else{
                        echo "ERROR: " . $connection->error;
                    }
                }
                else{
                    echo 'Passwords do not match';
                }
            }
        }
        else{
            echo "username cannot be empty";
        }
    }
    $connection->close();
?>