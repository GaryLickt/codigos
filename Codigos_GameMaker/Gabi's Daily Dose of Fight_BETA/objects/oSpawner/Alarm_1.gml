if (oControl.prepassou == false) and (yay == false) {
var bob = instance_create_layer(x, y-32, "Instances", oBigObstacle)
bob.direction = point_direction(x, y, x-1, y);
bob.speed = run;

alarm[1] = irandom_range(289,354)-(global.fase - 1);

}