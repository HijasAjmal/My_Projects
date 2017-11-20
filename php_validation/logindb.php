<?php

$tbname = "login";
$conn = mysqli_connect("localhost", "virus", ".virusdb", "Demo")or die("cannot connect");
$myusername = $_POST['usr'];
$mypassword = $_POST['pwd'];
$sql = "select Name, Email,Phone from login where Name = '$myusername' AND Password = '$mypassword'";
$result = mysqli_query($conn, $sql);
$row = $result->fetch_assoc();
if ($result == 1)
{
	echo "LOGIN SUCCESS";
	echo "<table><tr><th>Name</><th>Email</th><th>Phone</th><tr><td>" 
		.$row["Name"]. "</td><td>" .$row["Email"]. "</td><td>" 
		.$row["Phone"]."</td></tr></table> ";
}
else
{
	echo "INVALID COMBINATION";
}
?>
