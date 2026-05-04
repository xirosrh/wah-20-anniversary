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

def generate_teams(species_list, start_team=1):
    teams = []
    team_id = start_team

    for i in range(0, len(species_list), 6):
        team = species_list[i:i+6]
        if len(team) < 6:
            break  # ignora equipos incompletos

        team_block = f"""
[TEAM_{team_id}] =
{{
    .teamSize = 6,
    .team =
    {{
        {', '.join(team)}
    }},
}},
"""
        teams.append(team_block)
        team_id += 1

    return "\n".join(teams)

if __name__ == "__main__":
    species = extract_species("pokemon.txt")
    teams_c = generate_teams(species, start_team=1)

    with open("outputs/teams.c", "w", encoding="utf-8") as f:
        f.write(teams_c)

    print("Equipos generados correctamente → teams.c")
