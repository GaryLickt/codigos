if oMainConquistas.desafio_on = false{
	if global.level = 1 {
		if (oControl.prepassou == false) and (yay == false) {
			var bob = instance_create_layer(x, y, "Instances", oJumpObstacle)
			bob.direction = point_direction(x, y, x-1, y);
			bob.speed = run;
		}
	}
}else{
	if oMainConquistas.qual_desafio = "cinquentabarravinte" {
		if (oControl.prepassou == false) and (yay == false) {
			var bob = instance_create_layer(x, y, "Instances", oJumpObstacle)
			bob.direction = point_direction(x, y, x-1, y);
			bob.speed = run;

		}
	}
}

if oMainConquistas.desafio_on = false {
if global.fase <= 2 {
alarm[4] = irandom_range(149,254)/(global.fase);
}else{
alarm[4] = irandom_range(149,254)/(global.fase-1);
}
}else{
alarm[4] = irandom_range(149,254)-(0.05*oCounter.tempo);
}