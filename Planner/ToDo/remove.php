<?php 
    session_start();
    $db = "plannerByBeni";
    $connection = new mysqli("localhost","root","",$db);
    if(!$connection){
        echo "Failed to connect to the database";
    }
    else{
        if($_SERVER["REQUEST_METHOD"] == "POST"){
            $uname = $_SESSION["user"];
            $date = strtotime($_SESSION["date"]);
            $m = (int)(date("m", $date));
            $d = (int)(date("d", $date));
            $sql = "DELETE FROM `usertodo` WHERE month = '$m' AND day = '$d' AND username = '$uname'";
            if($connection->query($sql)){
                echo "Texts removed succesfully";
                header("location: index.php");
            }
            else{
                echo "Error removing texts from table<br>" . $connection->error;
            }
           
        }
        else{
            echo "SOMETHING WRONG";
        }
    }
    
?>