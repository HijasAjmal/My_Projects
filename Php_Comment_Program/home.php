<?php

require "settings.php";
session_start();
if ( ! isset($_SESSION['user_id'])) {
    header('Location:index.php?msg=please login');
}
if ($_GET['action'] == 'logout') {
    session_destroy();
    header('Location:index.php');
}

$db = new PDO('mysql:host=localhost;dbname=test', $settings['user'], $settings['pass']);

if (isset($_POST['comment'])) {
    $st = $db->prepare('insert into comment values(null, :user_id, :message)');
    $vals = [':user_id'=> $_SESSION['user_id'],
        ':message'=> $_POST['message']];
    if ( $st->execute($vals)) {
        header('Location:home.php');
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
<h3>Welcome <?= $_SESSION['name'] ?></h3>

<table border="1">
    <tr>
        <th>User</th>
        <th>Comment</th>
    </tr>
    <?php
    foreach ($db->query('select user_id, name, message from comment join user on user_id=user.id') as $comment) {
    ?>
    <tr>
        <td> <?= $comment['name'] ?> </td>
        <td> <?= $comment['message'] ?> </td>
    </tr>
    <?php
    }
    ?>

    </tr>
</table>

<h4>Add New Comment</h4>

<form action="" method="post">
    <label>Comment</label><input type="text" name="message">
    <input type="submit" name="comment">
</form>
<a href="?action=logout">Logout</a>
</body>
</html>
