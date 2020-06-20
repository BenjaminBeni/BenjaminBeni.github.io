<?php
    function actualize(){
        $servername = "localhost";
        $username = "root";
        $password = "";
        $dbname = "plannerbybeni";
        $connection = new mysqli($servername, $username, $password, $dbname);
        if ($connection->connect_error) {
            die("Connection failed: " . $connection->connect_error);
        }
        else{
            $uname = $_SESSION["user"];
            $currentmonth = (int)(date("m")); // Numarul lunii convertit in intreg
            $currentday = (int)(date("d")); // Ziua convertit in intreg
            $sql = $connection->prepare("DELETE FROM `usertodo` WHERE month < ? OR day < ?");
            $sql->bind_param("ii",$currentmonth, $currentday);
            $sql->execute();
        }
    }
?>