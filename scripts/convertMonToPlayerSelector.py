import re

def parse_ev_line(ev_line):
    # EVs vienen como: "252 Atk / 252 Spe / 4 HP"
    evs = {"HP": 0, "Atk": 0, "Def": 0, "Spe": 0, "SpA": 0, "SpD": 0}
    parts = ev_line.replace("EVs:", "").split("/")

    for part in parts:
        part = part.strip()
        if not part:
            continue

        tokens = part.split()
        if len(tokens) < 2:
            continue  # evita crasheos por líneas raras

        value = int(tokens[0])
        stat = tokens[1]
        evs[stat] = value

    # Orden requerido: hp, atk, def, speed, spatk, spdef
    return (
        evs["HP"],
        evs["Atk"],
        evs["Def"],
        evs["Spe"],
        evs["SpA"],
        evs["SpD"],
    )

def normalize_name(name):
    return name.upper().replace(" ", "_").replace("-", "_").replace("'", "")

def convert_showdown_to_c(filename):
    with open(filename, "r", encoding="utf-8") as f:
        blocks = f.read().split("\n\n")

    output = []

    for block in blocks:
        lines = [l.strip() for l in block.splitlines() if l.strip()]
        if not lines:
            continue

        # Primera línea: especie @ item
        first = lines[0]
        if "@" in first:
            species, item = [x.strip() for x in first.split("@")]
        else:
            species = first
            item = "NONE"

        species_id = normalize_name(species)
        item_id = normalize_name(item)

        ability = "ABILITY_NONE"
        nature = "NATURE_HARDY"
        evs = (0, 0, 0, 0, 0, 0)
        moves = []

        for line in lines[1:]:
            if line.startswith("Ability:"):
                ability = "ABILITY_" + normalize_name(line.split(":")[1].strip())
            elif line.startswith("EVs:"):
                evs = parse_ev_line(line)
            elif line.endswith("Nature"):
                nature = "NATURE_" + normalize_name(line.replace("Nature", "").strip())
            else:
                moves.append("MOVE_" + normalize_name(line))

        c_block = f"""
[MON_{species_id}] = {{
    .specie = SPECIES_{species_id},
    .ability = {ability},
    .nature = {nature},
    .itemId = ITEM_{item_id},
    .ev = TRAINER_PARTY_EVS({evs[0]}, {evs[1]}, {evs[2]}, {evs[3]}, {evs[4]}, {evs[5]}),
    .isShiny = FALSE,
    .moves = {{
        {', '.join(moves)}
    }},
}},
"""
        output.append(c_block)

    return "\n".join(output)

if __name__ == "__main__":
    result = convert_showdown_to_c("pokemon.txt")
    with open("outputs/output_party.txt", "w", encoding="utf-8") as f:
        f.write(result)

    print("Conversión completada → output_party.txt")
