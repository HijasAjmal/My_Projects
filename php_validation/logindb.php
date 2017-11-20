<?php

$tbname = "login";
$conn = mysqli_connect("localhost", "virus", ".virusdb", "Demo")or die("cannot connect");
//mysqli_select_db("$dbname")or die("cannot select DB");
$myusername = $_POST['usr'];
$mypassword = $_POST['pwd'];
//$myusername = stripslashes($myusername);
//$mypassword = stripslashes($mypassword);
//$myusername = mysqli_real_escape_string($myusername);
//$mypassword = mysqli_real_escape_string($mypassword);
$sql = "select Name, Email,Phone from login where Name = '$myusername' AND Password = '$mypassword'";
$result = mysqli_query($conn, $sql);
$row = $result->fetch_assoc();
$count = mysqli_num_rows($result);
if ($count == 1)
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
