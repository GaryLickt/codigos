/// @description Insert description here
// You can write your code in this editor
if oControl.cena1 = true {
	instance_destroy(b1);
	instance_destroy(b2);
	instance_destroy(b3);
	instance_destroy();
}

if (oAllan.y <= y) and (ready = true) {
	oControl.cena1 = true;
	instance_create_layer(753,564,"Instances",oTeddy);
	instance_create_layer(753,723,"Instances",oManequin);
	instance_create_layer(723,723,"Instances",oManequin);
	instance_create_layer(783,723,"Instances",oManequin);
	
	instance_create_layer(815,555,"Instances",oManequin);
	instance_create_layer(1072,594,"Instances",oManequin);
	instance_create_layer(1134,560,"Instances",oManequin);
	instance_create_layer(1229,590,"Instances",oManequin);
	
	instance_create_layer(871,595,"Instances",oManequin);
	instance_create_layer(946,528,"Instances",oManequin);
	instance_create_layer(1010,561,"Instances",oManequin);
	instance_destroy(b1);
	instance_destroy(b2);
	instance_destroy(b3);
	
	instance_destroy();
}

