if (oControl.prepassou == false) and (yay == false) {
var bob = instance_create_layer(x, y-32, "Instances", oObstacle)
bob.direction = point_direction(x, y, x-1, y);
bob.speed = run;

}

if global.fase <= 2 {
alarm[0] = irandom_range(60,120)/(global.level);
}else{
alarm[0] = irandom_range(60,120)/(global.level-1);
}