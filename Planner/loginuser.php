<?php
    session_start();
    $uname = $_POST['username'];
    $pwd = $_POST['password'];
    $db = "plannerByBeni";
    $connection = new mysqli("localhost", "root", "", $db);
    if(!$connection){
        die("Could not connect: " . $connection->connect_error);
    }
    if($_SERVER["REQUEST_METHOD"] == "POST"){
        $sql = "SELECT FirstName, LastName, username FROM PersonCredentials WHERE username = '$uname' AND pswrd = '$pwd' LIMIT 1";
        $result = $connection->query($sql);
        if($result && $result->num_rows){
            $row = $result->fetch_assoc();
            //echo $row["FirstName"] . " " . $row["LastName"];
            $_SESSION["fname"] = $row["FirstName"];
            $_SESSION["lname"] = $row["LastName"];
            $_SESSION["user"] = $row["username"];
            header("location: index.php");
        }
        else{
            echo "Something wrong with the search<br>" . $connection->error;
        }
    }
    
?>