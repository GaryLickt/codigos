/// @description Insert description here
// You can write your code in this editor
if oAllan.danger = false {
	ang += choose(-0.05,0,0.05);
	treme = 0;
}else{
	ang += choose(-0.5,0,0.5);
	treme = choose(0,0.01);
	if (point_distance(oAllan.x,oAllan.y, oMascotParent.x, oMascotParent.y) <= 200) {
		if (random_range(0,100) <= 50) {
		pisca = true;
		alarm[0] = 5;
		}
	}
}

