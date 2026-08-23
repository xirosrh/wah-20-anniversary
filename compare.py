from PIL import Image

def main():
    im1 = Image.open('graphics/summary_screen/swsh/tiles_original.png')
    im2 = Image.open('graphics/summary_screen/swsh/tiles.png')

    if im1.size != im2.size:
        print(f"Size diff: {im1.size} vs {im2.size}")
        return

    diff_coords = []
    for y in range(im1.height):
        for x in range(im1.width):
            if im1.getpixel((x,y)) != im2.getpixel((x,y)):
                diff_coords.append((x,y))

    print(f'Diff pixels: {len(diff_coords)}')
    if diff_coords:
        min_y = min(y for x,y in diff_coords)
        max_y = max(y for x,y in diff_coords)
        min_x = min(x for x,y in diff_coords)
        max_x = max(x for x,y in diff_coords)
        print(f'Bounding box of diff: X {min_x}-{max_x}, Y {min_y}-{max_y}')

if __name__ == '__main__':
    main()
