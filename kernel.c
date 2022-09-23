void kernelmain(void) {
	char *vidptr = (char*)0xb8000;
	char bg = ' ';
	const char *osname = "SomeOS";
	const char *welcomemessage = "Press any key to continue...";
	unsigned int screensize = 80 * 25 * 2;
	unsigned int i = 1034;
	unsigned int j = 0;

	while (j < screensize) {
		vidptr[j] = bg;
		vidptr[j+1] = 0x99;
		j = j + 2;
	}

	j = 0;

	while (osname[j] != '\0') {
		vidptr[i] = osname[j];
		vidptr[i + 1] = 0x9E;
		++j;
		i = i + 2;
	}

	j = 0;
	i += 928;

	while (welcomemessage[j] != '\0') {
		vidptr[i] = welcomemessage[j];
		vidptr[i + 1] = 0x9E;
		++j;
		i = i + 2;
	}

	return;
}