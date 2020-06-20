<?php session_start(); ?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Plan</title>
    <link rel = "stylesheet" type = "text/css" href = "CSS/css.css">
</head>
<body onload = "rdy()">
    <?php
        include('removeOld.php');
        if(!isset($_SESSION['fname'])){
            echo "
            <div id = 'notloggedDiv'>
            <h2 align = 'center'><u><i>You must be Logged in to use this site</i></u></h2>
            <p>You can login <a href = 'login.html'>here.</a></p>
            <p>Or create an account <a href = 'register.html'>now!</a></p>
            </div>
            ";
        }
        else{
            actualize();
            echo '
            <h2 align = "center" id = "time"></h2>
            <h2 align = "center"><i><u>Welcome ' . $_SESSION['fname'] . " " . $_SESSION['lname'] . ' </u></i></h2>
            <form action = "ToDo/logout.php" method = "POST" id = "logout">
            <input type = "submit" name = "submit" value = "Log Out" id = "logoutbtn">
            </form>
            <div id = "dnames">
                <div>Su</div>
                <div>Mo</div>
                <div>Tu</div>
                <div>We</div>
                <div>Th</div>
                <div>Fr</div>
                <div>Sa</div>
            </div>
        
            <div id = "days"></div>    
        
            <div id = "yandm">
                <div id = "years" onchange = "yearReset()">
                    <select id = "yearselector"></select>
                </div>
                <div id = "months">
                    <select onchange = "daysReset()" id = "monthselector"></select>
                </div>
            </div>
            <div id = "cont">
                Select a date
            </div>
            <form action = "sendSelected.php" method = "POST" id = "lform"> 
                <label for = "Year">Year = </label>
                <input type = "text" name = "year" value = "Year" readonly><br>
                <label for = "Month">Month = </label>
                <input type = "text" name = "month" value = "Month" readonly><br>
                <label for = "Day">Day = </label>
                <input type = "text" name = "day" value = "Day" readonly><br>
                <input type = "submit" value = "Plan" id = "submit">
            </form><br>
            ';
            if(isset($_SESSION["mustselect"])){
                echo '<h2 align = "center"><u><i>'. $_SESSION["mustselect"] . '</i></u></h2>';
                unset($_SESSION["mustselect"]);
            }
        }
    ?>
    <h2 align = "center" style = "margin-bottom : 0;"> &copy MIKLO BENJAMIN 2020 </h2>

    <script src = "JS/js.js"></script>  
</body>
</html>