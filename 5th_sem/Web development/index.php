<?php
session_start();
include 'db.php';

if (!isset($_SESSION['user'])) {
    header("Location: login.php");
    exit();
}

$name = $email = $faculty = "";
$edit_id = 0;

if (isset($_POST['save'])) {
    $name = trim($_POST['name']);
    $email = trim($_POST['email']);
    $faculty = trim($_POST['faculty']);

    if ($name == "" || $email == "" || $faculty == "") {
        echo "All fields are required!";
    } else {
        $sql = "INSERT INTO students (name, email, faculty) VALUES ('$name', '$email', '$faculty')";
        $conn->query($sql);
    }
}

if (isset($_GET['delete'])) {
    $id = $_GET['delete'];
    $conn->query("DELETE FROM students WHERE id=$id");
}

if (isset($_GET['edit'])) {
    $edit_id = $_GET['edit'];
    $result = $conn->query("SELECT * FROM students WHERE id=$edit_id");
    $row = $result->fetch_assoc();
    $name = $row['name'];
    $email = $row['email'];
    $faculty = $row['faculty'];
}

if (isset($_POST['update'])) {
    $id = $_POST['id'];
    $name = trim($_POST['name']);
    $email = trim($_POST['email']);
    $faculty = trim($_POST['faculty']);

    $conn->query("UPDATE students SET name='$name', email='$email', faculty='$faculty' WHERE id=$id");
}
?>

<!DOCTYPE html>
<html>
<head><title>Student Management System</title></head>
<body>
    <h2>Welcome, <?php echo $_SESSION['user']; ?></h2>
    <a href="logout.php">Logout</a>

    <h3><?php echo $edit_id ? "Update Student" : "Add Student"; ?></h3>
    <form method="post">
        <input type="hidden" name="id" value="<?php echo $edit_id; ?>">
        Name: <input type="text" name="name" value="<?php echo $name; ?>"><br><br>
        Email: <input type="email" name="email" value="<?php echo $email; ?>"><br><br>
        Faculty: <input type="text" name="faculty" value="<?php echo $faculty; ?>"><br><br>

        <?php if ($edit_id) { ?>
            <input type="submit" name="update" value="Update">
        <?php } else { ?>
            <input type="submit" name="save" value="Save">
        <?php } ?>
    </form>

    <h3>Student Records</h3>
    <table border="1" cellpadding="8">
        <tr>
            <th>ID</th><th>Name</th><th>Email</th><th>Faculty</th><th>Actions</th>
        </tr>
        <?php
        $result = $conn->query("SELECT * FROM students");
        while ($row = $result->fetch_assoc()) {
            echo "<tr>
                    <td>{$row['id']}</td>
                    <td>{$row['name']}</td>
                    <td>{$row['email']}</td>
                    <td>{$row['faculty']}</td>
                    <td>
                        <a href='index.php?edit={$row['id']}'>Edit</a> |
                        <a href='index.php?delete={$row['id']}'>Delete</a>
                    </td>
                  </tr>";
        }
        ?>
    </table>
</body>
</html>