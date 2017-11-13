<?php

$tbname = "login";
$conn = mysqli_connect("localhost", "virus", ".virusdb", "ssn")or die("cannot connect");
//mysqli_select_db("$dbname")or die("cannot select DB");
$myusername = $_POST['usr'];
$emai = $_POST['email'];
$phon = $_POST['phone'];
$mypassword = $_POST['pwd'];
////$myusername = stripslashes($myusername);
////$mypassword = stripslashes($mypassword);
////$myusername = mysqli_real_escape_string($myusername);
////$mypassword = mysqli_real_escape_string($mypassword);
$sql = "insert into login values('$myusername','$emai','$phon','$mypassword')";
$result = mysqli_query($conn,$sql);
$count = mysqli_num_rows($result);
if ($count == 1)
{
	echo "Registration SUCCESS";
	}
?>
