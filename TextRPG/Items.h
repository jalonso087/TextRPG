

class Items : public Player
{
private:

	const enum usable
	{
		I_HEALTHPOTION,
		I_ENERGYPOTION,
		I_KEY,
		I_TOWNPORTAL
	};

protected:

public:

	int spawnItem()
	{
		return random_num(I_HEALTHPOTION, I_HEALTHPOTION);
	}

};