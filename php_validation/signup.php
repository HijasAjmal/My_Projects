<?php

$tbname = "login";
$conn = mysqli_connect("localhost", "virus", ".virusdb", "ssn")or die("cannot connect");
$myusername = $_POST['usr'];
$emai = $_POST['email'];
$phon = $_POST['phone'];
$mypassword = $_POST['pwd'];
$sql = "insert into login values('$myusername','$emai','$phon','$mypassword')";
$result = mysqli_query($conn,$sql);
$count = mysqli_num_rows($result);
if ($count == 1)
{
	echo "Registration SUCCESS";
	}
?>
