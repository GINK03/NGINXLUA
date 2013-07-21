<?php
$con=mysql_connect("localhost","root","91nk9003");
if (!$con) {
  die('cannot connet mysql server'.mysql_error());
}
$db_selected = mysql_select_db('testvs', $con);
$res = mysql_query('SELECT * FROM vs');
$data = mysql_fetch_assoc($res);
echo "<body>";
echo "Wellcome to PHP5.2 world</br>";
echo "MySql Counter: ".$data['count']."</br>";
echo "it's too hot</br>";
echo "keys: </br>";
echo "</body>";
if(!$res){
  die('missing die'.mysql_error());
};
$next_count = ++$data['count'];
//echo $next_count;
$sql = "UPDATE vs SET count = ".$next_count." where keyname = '___count___';";
$result_flag = mysql_query($sql);
if (!$result_flag) {
  die('insert missing'.mysql_error());
};
mysql_close($con);
?>
