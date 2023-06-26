/// @description Insert description here
// You can write your code in this editor
if oGabiBoss1.dead = false {
if extra_hp <= 0 {
hp -= 50;
}else{
extra_hp -= 50;
}

instance_destroy(other);
}