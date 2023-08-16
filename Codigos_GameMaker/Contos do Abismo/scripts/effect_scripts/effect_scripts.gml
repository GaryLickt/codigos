// Script assets have changed for v2.3.0 see
// https://help.yoyogames.com/hc/en-us/articles/360005277377 for more information
function approach(_from, _to, _delta)
{
    if (_from < _to)
    {
        return min(_from + _delta, _to); 
    }
    else
    {
        return max(_from - _delta, _to);
    }
}
