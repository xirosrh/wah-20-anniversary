def normalize_name(name):
    return name.upper().replace(" ", "_").replace("-", "_").replace("'", "")

def extract_species(filename):
    species_list = []

    with open(filename, "r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue

            # Detecta líneas tipo: "Tyranitar @ Assault Vest"
            if "@" in line:
                species = line.split("@")[0].strip()
                species_list.append("MON_" + normalize_name(species))

    return species_list

if __name__ == "__main__":
    species = extract_species("pokemon.txt")

    # Escribimos todos los nombres en formato lista
    with open("outputs/pokemon_list.txt", "w", encoding="utf-8") as f:
        f.write("[\n")
        for p in species:
            f.write(f"    {p},\n")
        f.write("]\n")

    print("Lista de Pokémon generada correctamente → pokemon_list.txt")
