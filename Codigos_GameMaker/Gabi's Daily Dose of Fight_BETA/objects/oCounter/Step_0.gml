/// @description Insert description here
// You can write your code in this editor
if oGabi.dead = false {
tempo += 0.01;
kik += 0.01;

if (kik >= 5) and (oControl.cock > 1) {
	kik = 0;
	oControl.cock -= 3;
}
switch(oMainConquistas.qual_desafio){
case "afogados":
	if tempo > global.debaixodaguatempo {
	global.debaixodaguatempo = tempo;
	};break;
case "distorcido":
	if tempo > global.distorcidotempo {
	global.distorcidotempo = tempo;
	};break;
case "cinquentabarravinte":
	if tempo > global.cinquentabarravintetempo {
	global.cinquentabarravintetempo = tempo;
	};break;
case "correnegada":
	if tempo > global.correnegada {
	global.correnegadatempo = tempo;
	};break;
case "chaolava":
	if tempo > global.chaolava {
	global.chaolavatempo = tempo;
	};break;
case "sempulo":
	if tempo > global.sempulo {
	global.sempulotempo = tempo;
	};break;
}
}

