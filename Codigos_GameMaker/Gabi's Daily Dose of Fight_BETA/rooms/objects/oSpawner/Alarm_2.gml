if oMainConquistas.desafio_on = false{
	if global.level = 1 {
		if (oControl.prepassou == false) and (yay == false) {
			var bob = instance_create_layer(x, y-(182 + irandom_range(-20,20)), "Instances", oFlyObstacle)
			bob.direction = point_direction(x, y, x-1, y);
			bob.speed = run;

		}
	}
	if global.level = 2 {
		if (oControl.prepassou == false) and (yay == false) {
			var bob = instance_create_layer(x, y-(irandom_range(0,182)), "Instances", oShadowFly)
			bob.direction = point_direction(x, y, x-1, y);
			bob.speed = run+2;

		}
	}
}else{
	if oMainConquistas.qual_desafio = "cinquentabarravinte" {
		if (oControl.prepassou == false) and (yay == false) {
			var bob = instance_create_layer(x, y-(182 + irandom_range(-20,20)), "Instances", oFlyObstacle)
			bob.direction = point_direction(x, y, x-1, y);
			bob.speed = run;

			var bob = instance_create_layer(x, y-(irandom_range(0,182)), "Instances", oShadowFly)
			bob.direction = point_direction(x, y, x-1, y);
			bob.speed = run+2;

		}
	}
}

if oMainConquistas.desafio_on = false {
if global.fase <= 2 {
alarm[2] = choose(irandom_range(163,249),30);
}else{
alarm[2] = irandom_range(163,249);
}
}else{
alarm[2] = irandom_range(163,249)-(0.05*oCounter.tempo);
}