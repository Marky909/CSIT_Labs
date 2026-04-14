<?php
session_start();
include 'db.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = trim($_POST['username']);
    $password = trim($_POST['password']);

    if (!empty($_POST['remember'])) {
        setcookie("username", $username, time() + (7 * 24 * 60 * 60), "/");
    }

    $sql = "SELECT * FROM users WHERE username='$username' AND password='$password'";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        $_SESSION['user'] = $username;
        header("Location: index.php");
        exit();
    } else {
        echo "Invalid login!";
    }
}
?>

<!DOCTYPE html>
<html>
<head><title>Login</title></head>
<body>
    <h2>Login</h2>
    <form method="post">
        Username: <input type="text" name="username" value="<?php echo isset($_COOKIE['username']) ? $_COOKIE['username'] : ''; ?>"><br><br>
        Password: <input type="password" name="password"><br><br>
        <input type="checkbox" name="remember"> Remember Me<br><br>
        <input type="submit" value="Login">
    </form>
</body>
</html>