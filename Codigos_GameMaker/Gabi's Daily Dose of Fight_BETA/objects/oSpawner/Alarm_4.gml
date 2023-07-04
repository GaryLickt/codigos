if (oControl.prepassou == false) and (yay == false) {
var bob = instance_create_layer(x, y, "Instances", oJumpObstacle)
bob.direction = point_direction(x, y, x-1, y);
bob.speed = run;

}

if global.fase <= 2 {
alarm[4] = irandom_range(149,254)/(global.fase);
}else{
alarm[4] = irandom_range(149,254)/(global.fase-1);
}