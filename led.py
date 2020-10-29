from PIL import Image, ImageDraw, ImageGrab


def get_colors(numcolors=8):
    img = ImageGrab.grab()
    img = img.copy()
    img.thumbnail((192, 108))

    paletted = img.convert('P', palette=Image.ADAPTIVE, colors=numcolors)

    palette = paletted.getpalette()
    color_counts = sorted(paletted.getcolors(), reverse=True)
    colors = list()
    for i in range(numcolors):
        palette_index = color_counts[i][1]
        dominant_color = palette[palette_index * 3:palette_index * 3 + 3]
        colors.append(tuple(dominant_color))

    return colors


def save_palette(colors, swatchsize=20, outfile="palette.png"):
    num_colors = len(colors)
    palette = Image.new('RGB', (swatchsize * num_colors, swatchsize))
    draw = ImageDraw.Draw(palette)

    posx = 0
    for color in colors:
        draw.rectangle([posx, 0, posx + swatchsize, swatchsize], fill=color)
        posx = posx + swatchsize

    del draw
    palette.save(outfile, "PNG")


def max_brightness(r, g, b):
    tmp = 255 / max((r, g, b))
    r *= tmp
    g *= tmp
    b *= tmp
    return int(round(r)), int(round(g)), int(round(b))
