/// @description Insert description here
// You can write your code in this editor

depth = -200
minDistance = -1;

with(oChao)
{
    // Verifique se o objeto "obj_B" está abaixo de "obj_A"
    if (y > other.y)
    {
        // Calcule a distância entre "obj_A" e "obj_B"
        var distance = point_distance(x, y, other.x, other.y);
        
        // Verifique se a distância é menor do que a mínima encontrada anteriormente
        if (other.minDistance == -1 || distance < other.minDistance)
        {
            // Atualize a distância mínima
            other.minDistance = distance/32;
        }
    }
}

// Verifique se a distância mínima foi atualizada
if (minDistance != -1)
{
	var repeticoes = minDistance;
	var ypos = y+32

	while (repeticoes > 0)
	{
		instance_create_layer(x, ypos,"Instances", oBossMarcoShockRay);
		repeticoes -= 1
		ypos += 32
	}
}

