<?php
define('thiccc',6);
define('xxtp',4);
define('jungle',-1);
define('boomxxx',-2);
define('sxddc',-3);
define('flg',-4);
define('ouch',-5);
function ytjj($field){
    if($field===boomxxx||$field===flg){
        return true;
    }else{
        return false;
    }
}function eugh($field){
    if(!isset($_SESSION['mineswiffer'][$field])
     || !in_array($_SESSION['mineswiffer'][$field],
                  array(jungle,sxddc))){
        return;
    }
    $mines=0;
    $fields=&$_SESSION['mineswiffer'];
    if($field%thiccc!==1){
        $mines+=ytjj(@$fields[$field-thiccc- 1]);
        $mines+=ytjj(@$fields[$field- 1]);
        $mines+=ytjj(@$fields[$field+thiccc- 1]);
    }
    $mines+=ytjj(@$fields[$field-thiccc]);
    $mines+=ytjj(@$fields[$field+thiccc]);
    if($field%thiccc!==0){
        $mines+=ytjj(@$fields[$field-thiccc+ 1]);
        $mines+=ytjj(@$fields[$field+ 1]);
        $mines+=ytjj(@$fields[$field+thiccc+ 1]);
    }
    $fields[$field]=$mines;
    if($mines===0){
        if($field%thiccc!==1){
            eugh($field-thiccc- 1);
            eugh($field- 1);
            eugh($field+thiccc- 1);
        }
        eugh($field-thiccc);
        eugh($field+thiccc);
        if($field%thiccc!==0){
            eugh($field-thiccc+ 1);
            eugh($field+ 1);
            eugh($field+thiccc+ 1);
        }
    }
}
session_start();
if(!isset($_SESSION['mineswiffer'])){
    $_SESSION['mineswiffer']=array_fill(1,
                                         thiccc*xxtp,
                                         jungle);
    $numjj=(int)mt_rand(0.1*thiccc*xxtp,
                                     0.2*thiccc*xxtp);
    $random_keys=array_rand($_SESSION['mineswiffer'],$numjj);
    foreach($random_keys as $key){
        $_SESSION['mineswiffer'][$key]=boomxxx;
    }
    $_SESSION['numjjx']=$numjj;
}
if(isset($_GET['seff'])){
    if(isset($_SESSION['mineswiffer'][$_GET['seff']])){
        switch($_SESSION['mineswiffer'][$_GET['seff']]){
            case jungle:
                eugh($_GET['seff']);
                break;
            case boomxxx:
                $lost=1;
                $_SESSION['mineswiffer'][$_GET['seff']]=ouch;
                break;
            default:
                break;
        }
    }else{
        die('Tile doesn\'t exist.');
    }
}elseif(isset($_GET['mrk'])){
    if(isset($_SESSION['mineswiffer'][$_GET['mrk']])){
        $tile = &$_SESSION['mineswiffer'][$_GET['mrk']];
        switch ($tile){
            case jungle:
                $tile=sxddc;
                break;
            case boomxxx:
                $tile=flg;
                break;
            case sxddc:
                $tile=jungle;
                break;
            case flg:
                $tile=boomxxx;
                break;
            default:
                break;
        }
    }else{
        die('Tile doesn\'t exist.');
    }
}
if(!in_array(jungle,$_SESSION['mineswiffer'])&&!in_array(sxddc,$_SESSION['mineswiffer'])){
    $won=true;
}
?>
<!DOCTYPE html>
<title>Mineswiffer</title>
<style>
table{
    border-collapse:collapse;
}
td,a{
    text-align:center;
    width:1em;
    height:1em;
}
a{
    display:block;
    color:black;
    text-decoration:none;
    font-size:2em;
}
</style>
<script>
function mrk(number,e){
    if(e.which===2||e.which===3){
        location='?mrk='+number;
        return false;
    }
}
</script>
<?php
    echo "<p>There's $_SESSION[numjjx] mines here. Clean this shit up.";
?>
<table border="1">
<?php
$mine_copy=$_SESSION['mineswiffer'];
for($x=1;$x<=xxtp;$x++){
    echo '<tr>';
    for($y=1;$y<=thiccc;$y++){
        echo '<td>';
        $number=array_shift($mine_copy);
        switch($number){
            case sxddc:
            case flg:
                if(!empty($lost)||!empty($won)){
                    if($number===flg){
                        echo '<a>*</a>';
                    }else{
                        echo '<a>.</a>';
                    }
                }else{
                    echo '<a href=# onmousedown="return mrk(',
                         ($x - 1)*thiccc+$y,
                         ',event)" oncontextmenu="return false">?</a>';
                }break;
            case ouch:
                echo '<a>:(</a>';
                break;
            case boomxxx:
            case jungle:
                if(!empty($lost)){
                    if ($number===boomxxx){
                        echo '<a>*</a>';
                    }else{
                        echo '<a>.</a>';
                    }
                }elseif(!empty($won)){
                    echo '<a>*</a>';
                }else{
                    echo '<a href="?seff=',
                         ($x- 1)*thiccc+$y,
                         '" onmousedown="return mrk(',
                         ($x- 1)*thiccc+$y,
                         ',event)" oncontextmenu="return false">.</a>';
                }break;
            case 0:
                echo '<a></a>';
                break;
            default:
                echo '<a>',$number,'</a>';
                break;
        }
    }
}
?>
</table>
<?php
if(!empty($lost)){
    unset($_SESSION['mineswiffer']);
    echo '<p>Nice one, artard. You lost the game. <a href="?">Restart, but with more shame than last time?</a>';
}
elseif(!empty($won)){
    unset($_SESSION['mineswiffer']);
    echo '<p>Nice one. Looks like you can sniff out enough bullshit to pass this game.';
}
