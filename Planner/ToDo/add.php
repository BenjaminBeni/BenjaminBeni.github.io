<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);
    session_start();
    $db = "plannerByBeni";
    $connection = new mysqli("localhost","root","",$db);
    if(!$connection){
        echo "Failed to connect to the database";
    }
    else{
        if($_SERVER["REQUEST_METHOD"] == "POST"){
            $text = $_POST["text"];
            $uname = $_SESSION["user"];
            $date = strtotime($_SESSION["date"]);
            $m = (int)date("m", $date);
            $d = (int)date("d", $date);
            $sql = "INSERT INTO `usertodo` VALUES(?,?,?,?)";
            if($query = $connection->prepare($sql)){
                $query->bind_param("ssii", $text, $uname, $m, $d);
                $query->execute();
                echo "Text added succesfully";
            }
            else{
                echo $connection->errno . " " . $connection->error;
            }
        }
    }
    header("location: index.php");
?>