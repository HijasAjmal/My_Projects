<?php

$tbname = "login";
$conn = mysqli_connect("localhost", "virus", ".virusdb", "ssn")or die("cannot connect");
//mysqli_select_db("$dbname")or die("cannot select DB");
$myusername = $_POST['usr'];
$mypassword = $_POST['pwd'];
//$myusername = stripslashes($myusername);
//$mypassword = stripslashes($mypassword);
//$myusername = mysqli_real_escape_string($myusername);
//$mypassword = mysqli_real_escape_string($mypassword);
$sql = "select * from login where Name = '$myusername' AND Password = '$mypassword'";
$result = mysqli_query($conn, $sql);
$count = mysqli_num_rows($result);
if ($count == 1)
{
	echo "LOGIN SUCCESS";
}
else
{
	echo "INVALID COMBINATION";
}
?>
