# Draws the engine's icon, Source/Main/res/Iblis.ico (an original design: a gold eight-pointed star over a dark red
# disc). Needs Pillow:  python tools/make_icon.py Source/Main/res/Iblis.ico preview.png
import math, sys
from PIL import Image, ImageDraw
def draw(n):
    S = n * 8
    im = Image.new("RGBA", (S, S), (0, 0, 0, 0)); d = ImageDraw.Draw(im)
    c = S / 2
    for i in range(int(c), 0, -1):  # radial disc
        t = i / c
        d.ellipse([c - i, c - i, c + i, c + i], fill=(int(40 + 110 * (1 - t)), int(6 + 10 * (1 - t)), 10, 255))
    d.ellipse([S * .04, S * .04, S * .96, S * .96], outline=(200, 150, 60, 255), width=max(1, S // 32))
    pts = []
    for k in range(16):
        a = -math.pi / 2 + k * math.pi / 8
        r = S * (0.40 if k % 2 == 0 else 0.15)
        pts.append((c + r * math.cos(a), c + r * math.sin(a)))
    d.polygon(pts, fill=(235, 190, 80, 255), outline=(120, 70, 20, 255))
    d.ellipse([c - S * .06, c - S * .06, c + S * .06, c + S * .06], fill=(90, 10, 10, 255))
    return im.resize((n, n), Image.LANCZOS)
sizes = [16, 24, 32, 48, 64, 256]
big = draw(256)
big.save(sys.argv[1], format="ICO", sizes=[(s, s) for s in sizes], append_images=[draw(s) for s in sizes[:-1]])
draw(64).save(sys.argv[2])
