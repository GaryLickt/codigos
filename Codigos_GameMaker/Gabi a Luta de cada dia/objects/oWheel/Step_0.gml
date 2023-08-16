/// Step Event - obj_boomerang

if room_get_name(room) = "Room1" {

// Variáveis
var maxDistance = 400; // Distância máxima que o bumerangue percorrerá antes de subir
var revSpeed = speed + 4

// Movimentação do bumerangue
if !boomerangReturning {
    // Movimento horizontal reto
    x += lengthdir_x(speed, direction);
    y += lengthdir_y(speed, direction);
    
    // Verifica se atingiu a distância limite
    if distance_to_object(oGabi) >= maxDistance {
        // Define que o bumerangue está retornando
		speed = revSpeed
		direction = point_direction(x, y, oGabi.x, oGabi.y+15);
        boomerangReturning = true;
    }
} else {
    // Movimento vertical
	direction = point_direction(x, y, oGabi.x, oGabi.y+30);
	x += lengthdir_x(speed, direction);
    y += lengthdir_y(speed, direction);
    
    // Verifica se o bumerangue retornou ao personagem
    if distance_to_object(oGabi) <= sprite_width / 2 {
        // Remove o objeto do bumerangue
		oGabi.skill2 = 30;
        instance_destroy();
        

	}
}
if oGabi.estado = scr_player_ded {
instance_destroy();
}

}

if room_get_name(room) = "RoomBoss1" {
// Variáveis
var maxDistance = 400; // Distância máxima que o bumerangue percorrerá antes de subir
var revSpeed = speed + 4

// Movimentação do bumerangue
if !boomerangReturning {
    // Movimento horizontal reto
    x += lengthdir_x(speed, direction);
    y += lengthdir_y(speed, direction);
    
    // Verifica se atingiu a distância limite
    if distance_to_object(oGabiBoss1) >= maxDistance {
        // Define que o bumerangue está retornando
		if speed > 0 {
		speed -= 0.05
		}else{
		speed = revSpeed
		}
		direction = point_direction(x, y, oGabiBoss1.x, oGabiBoss1.y+15);
        boomerangReturning = true;
    }
} else {
    // Movimento vertical
	direction = point_direction(x, y, oGabiBoss1.x, oGabiBoss1.y+15);
	x += lengthdir_x(speed, direction);
    y += lengthdir_y(speed, direction);
    
    // Verifica se o bumerangue retornou ao personagem
    if distance_to_object(oGabiBoss1) <= sprite_width / 2 {
        // Remove o objeto do bumerangue
		oGabiBoss1.skill2 = 30;
        instance_destroy();
        

	}
}

if oGabiBoss1.estado = scr_player_boss_ded {
instance_destroy();
}
}
	
if room_get_name(room) = "RoomBoss2" {
// Variáveis
var maxDistance = 400; // Distância máxima que o bumerangue percorrerá antes de subir
var revSpeed = speed + 4

// Movimentação do bumerangue
if !boomerangReturning {
    // Movimento horizontal reto
    x += lengthdir_x(speed, direction);
    y += lengthdir_y(speed, direction);
    
    // Verifica se atingiu a distância limite
    if distance_to_object(oGabiBoss2) >= maxDistance {
        // Define que o bumerangue está retornando
		if speed > 0 {
		speed -= 0.05
		}else{
		speed = revSpeed
		}
		direction = point_direction(x, y, oGabiBoss2.x, oGabiBoss2.y+15);
        boomerangReturning = true;
    }
} else {
    // Movimento vertical
	direction = point_direction(x, y, oGabiBoss2.x, oGabiBoss2.y+15);
	x += lengthdir_x(speed, direction);
    y += lengthdir_y(speed, direction);
    
    // Verifica se o bumerangue retornou ao personagem
    if distance_to_object(oGabiBoss2) <= sprite_width / 2 {
        // Remove o objeto do bumerangue
		oGabiBoss2.skill2 = 30;
        instance_destroy();
        

	}
}

if oGabiBoss2.estado = scr_player_boss_ded {
instance_destroy();
}
}