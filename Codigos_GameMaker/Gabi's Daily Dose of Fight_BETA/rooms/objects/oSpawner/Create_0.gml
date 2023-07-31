randomize();
run = 6 + (0.05 * global.fase+1);
runcenario = run - 2;
runcenario2 = runcenario - 4;
runcenario3 = runcenario - 5;
yay = false;
if oMainConquistas.desafio_on = false {
	if global.level = 1 {
		if global.fase >= 1 {
		alarm[0] = choose(60,120) / global.fase;
		alarm[1] = choose(195,255) / global.fase;
		}
		if global.fase >= 4 {
		alarm[2] = choose(63,149) / global.fase;
		}
		if global.fase >= 2 {
		alarm[3] = choose(123,239) / global.fase;
		}
		if global.fase >= 3 {
		alarm[4] = choose(149,254) / global.fase;
		}
	}
	if global.level = 2 {
		if global.fase >= 1 {
		alarm[0] = choose(60,120) / global.fase;
		alarm[1] = choose(195,255) / global.fase;
		}
		if global.fase >= 2 {
		alarm[2] = choose(63,149) / global.fase;
		}
		if global.fase >= 3 {
		alarm[3] = choose(123,239) / global.fase;
		}
	}
}else{
	if oMainConquistas.qual_desafio = "distorcido" {
	alarm[0] = choose(60,120);
	alarm[1] = choose(195,255);
	}
	if oMainConquistas.qual_desafio = "sempulo" {
	alarm[0] = choose(60,120);
	alarm[1] = choose(195,255);
	}
	if oMainConquistas.qual_desafio = "afogados" {
	alarm[0] = choose(60,120);
	alarm[1] = choose(195,255);
	}
	if oMainConquistas.qual_desafio = "correnegada" {
	alarm[0] = choose(60,120);
	alarm[1] = choose(195,255);
	}
	if oMainConquistas.qual_desafio = "cinquentabarravinte" {
	alarm[0] = choose(60,120);
	alarm[1] = choose(195,255);
	alarm[2] = choose(63,149);
	alarm[3] = choose(123,239);
	alarm[4] = choose(149,254);
	}
}