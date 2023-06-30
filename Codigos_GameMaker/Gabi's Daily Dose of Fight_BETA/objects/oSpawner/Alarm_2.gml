if global.level = 1 {
if (oControl.prepassou == false) and (yay == false) {
var bob = instance_create_layer(x, y-(182 + irandom_range(-20,20)), "Instances", oFlyObstacle)
bob.direction = point_direction(x, y, x-1, y);
bob.speed = run;

alarm[2] = irandom_range(163,249)-(global.fase - 1);

}
}
if global.level = 2 {
if (oControl.prepassou == false) and (yay == false) {
var bob = instance_create_layer(x, y-(irandom_range(0,182)), "Instances", oShadowFly)
bob.direction = point_direction(x, y, x-1, y);
bob.speed = run+2;

alarm[2] = choose(irandom_range(163,249)-(global.fase - 1),30);

}
}