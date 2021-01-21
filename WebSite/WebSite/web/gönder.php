<?php
session_start();
if(isset($_POST['kullanici_giris']))
{
  if($_POST['k_adi']=="g191210068@sakarya.edu.tr"&&$_POST['pass']=="1234")
  {
	$_SESSÝON['k_adi']=$_POST['k_adi'];
	$_SESSÝON['pass']=$_POST['pass'];

	if(isset($_POST['beni_hatirla']))
	{
		setcookie("k_adi","g191210068@sakarya.edu.tr",strtotime("+1 day"));
		setcookie("pass","1234",strtotime("+1 day"));
	}
	else
	{
	    setcookie("k_adi","g191210068@sakarya.edu.tr",strtotime("-1 day"));
		setcookie("pass","1234",strtotime("-1 day"));
	}
	echo("HOSGELDINIZ G191210068..ANASAYFAYA YONLENDIRILIYORSUNUZ..");
	 header("Refresh:3 ; url=anasayfa.html");
  }
    else
	{
	  header("Location:login.html");
	  exit;
	}
}
?>