<?php session_start(); ?>
<!DOCTYPE html>
<html lang="en">
  <head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>To Do List</title>
    <link rel="stylesheet" href="css.css">
  </head>
  <body>
    <?php
        if(isset($_SESSION["date"])){
            //echo $_SESSION["user"];
            echo "
                <div id = 'firstdiv'>
                    <h2><u><i>The Date you are planning for: ".$_SESSION["date"]."</i></u></h2>
                    <div style = 'width: auto; height: auto;'>
                        <a class = 'a' href = '../index.php' align = 'center'>Select another date</a>
                    </div>
                    <div id = 'logoutform'>
                        <form action = 'logout.php' method = 'POST' >
                        <label for = 'lgbtn'><input type = 'submit' value = 'Logout' name = 'lgbtn' id = 'logoutbutton'>
                        </label></form><br>
                    </div>
                </div>
                <form action = 'add.php' method = 'POST'>
                    <textarea name = 'text' id = 'text' placeholder = 'Enter your plan here  ... ' rows = '6' cols = '50'></textarea><br>
                    <input type = 'submit' name = 'submit' id = 'submit' value = 'Add'>
                </form>
                <ul>";
                
                $db = "plannerByBeni";
                $connection = new mysqli("localhost", "root", "", $db);
                if(!$connection){
                    die("Could not connect: " . $connection->connect_error);
                }
                else{
                    $uname = $_SESSION["user"];
                    $date = strtotime($_SESSION["date"]);
                    $m = (int)(date("m", $date));
                    $d = (int)(date("d", $date));
                    $sql = "SELECT * FROM `usertodo` WHERE username = '$uname'";
                    $result = $connection->query($sql);
                    $i = 0;
                    while($result && $i < $result->num_rows){
                        $row = $result->fetch_assoc();
                        if($row){
                            $m2 = $row["month"];
                            $d2 = $row["day"];
                            if($m2 == $m && $d2 == $d){
                                echo "<li>" . $row["text"] . "</li>";
                            }
                        }
                        else{
                            break;
                        }
                    }
                }
                echo "</ul>";
                echo '
                    <form action = "remove.php" method = "POST" id = "remForm">
                        <input type = "submit" name = "submit" value= "Remove Plans" id = "remove">
                    </form>'; 
        }
        else{
            echo "
                <div id = 'notloggedDiv'>
                <h2 align = 'center'><u><i>You must be Logged in to use this site</i></u></h2>
                <p>You can login <a href = '../login.php'>here.</a></p>
                <p>Or create an account <a href = '../register.php'>now!</a></p>
                </div>
            ";
        }
    ?>
  </body>
</html>
