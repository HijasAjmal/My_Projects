<?php

require "settings.php";
if (isset($_SESSION['user_id'])) {
    //header('Location:home.php');
}
if (isset($_POST['login'])) {

    $db = new PDO('mysql:host=localhost;dbname=test', $settings['user'], $settings['pass']);
    $st = $db->prepare('select * from user where name=:name and password=:password');
    $vals = [':name'=> $_POST['name'],
        ':password'=> $_POST['password']];
    $st->execute($vals);
    $user = $st->fetchObject();
    if($user != false) {
        session_start();
        $_SESSION['user_id'] = $user->id;
        $_SESSION['name'] = $user->name;
        header('Location:home.php');
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
<?= @$_GET['msg'] ?>
<h3>Login</h3>
<form action="" method="post">
    <label>name</label><input name="name" type="text">
    <label>password</label><input name="password" type="password">
    <input name="login" type="submit">
</form>
<a href="reg.php">Registration</a>
</body>
</html>
