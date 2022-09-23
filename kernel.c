void kernelmain(void) {
	char *vidmemptr = (char*)0xb8000; //video memory pointer
	char bg = ' '; //background
	const char *osname = "SomeOS"; //name
	const char *welcomemessage = "Press any key to continue..."; //message
	unsigned int screensize = 80 * 25 * 2; //size
	unsigned int i = 1034; //counter to place name and welcome
	unsigned int j = 0; //iterator

	while (j < screensize) {
		vidptr[j] = bg; //console clear
		vidptr[j+1] = 0x99; //blue background
		j = j + 2;
	}

	j = 0;

	while (osname[j] != '\0') {
		vidptr[i] = osname[j]; //writing os name
		vidptr[i + 1] = 0x9E; //yellow text color
		++j;
		i = i + 2;
	}

	j = 0;
	i += 928;

	while (welcomemessage[j] != '\0') {
		vidptr[i] = welcomemessage[j]; //writing welcome
		vidptr[i + 1] = 0x9E; //yellow text color
		++j;
		i = i + 2;
	}

	return;
}
