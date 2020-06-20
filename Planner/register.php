<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Register</title>
    <link rel = "stylesheet" type = "text/css" href = "CSS/register.css">
</head>
<body onload = "rdy()">
    <form action = "registeruser.php" method = "POST" enctype="multipart/form-data" id = "loginform">
        <u><strong><i><h5 align = "center">Register</i></strong></u></h5>
        <div class = "forlabels">
            <label for = "username"><u><strong><i>Username: </i></strong></u></label>
            <input type = "text" name = "username" id = "username" required autocomplete = "off"><br>
        </div>
        <br>
        <div class = "forlabels">
            <label for = "fname"><u><strong><i>First Name: </i></strong></u></label>
            <input type = "text" name = "fname" id = "fname" autocomplete = "off"><br>
        </div>
        <br>
        <div class = "forlabels">
            <label for = "lname"><u><strong><i>Last Name: </i></strong></u></label>
            <input type = "text" name = "lname" id = "lname" autocomplete = "off"><br>
        </div>
        <br>
        <div class = "forlabels">
            <label for = "email"><u><strong><i>E-mail: </i></strong></u></label>
            <input type = "text" name = "email" id = "email" required autocomplete = "off"><br>
        </div>
        <br>
        <div class = "forlabels">
            <label for = "password"><u><strong><i>Password: </i></strong></u></label>
            <input type = "password" name = "password" id = "password" required autocomplete = "off"><br>
        </div>
        <br>
        <div class = "forlabels">
            <label for = "cpassword"><u><strong><i>Confirm Password: </i></strong></u></label>
            <input type = "password" name = "cpassword" id = "cpassword" required autocomplete = "off"><br>
        </div>
        <br>
        <input type="submit" value="Register" name="submit" id = "submit">
    </form>
    <script src = "JS/rjs.js"></script>
</body>
</html>