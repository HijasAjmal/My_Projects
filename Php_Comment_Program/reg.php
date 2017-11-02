<?php

require "settings.php";
if (isset($_POST['register'])) {

    header('Location:/?msg=register_success');
    $db = new PDO('mysql:host=localhost;dbname=test', $settings['user'], $settings['pass']);
    $st = $db->prepare('insert into user values(null, :name, :password, :mobile, :email)');
    $vals = [':name'=> $_POST['name'],
        ':password'=> $_POST['password'],
        ':mobile'=> $_POST['mobile'],
        ':email'=> $_POST['email']];
    if ( $st->execute($vals)) {
        header('Location:index.php?msg=register_success');
    } else {
        echo "\nPDOStatement::errorInfo():\n";
        $arr = $st->errorInfo();
        print_r($arr);
    }
}

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title></title>
</head>
<body>
   <h2>Registration</h2>
    <form method="post" action="">
        <label>Name</label><input name="name" type="text"><br>
        <label>Password</label><input name="password" type="password"><br>
        <label>Mobile</label><input name="mobile" type="text"><br>
        <label>Email</label><input name="email" type="text"><br>
        <input name="register" type="submit" value="Register">
    </form>
</body>
</html>
