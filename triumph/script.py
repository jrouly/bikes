def sa_aw_ratio(front):
  rear = 18 # 18T rear cog
  ratio = front / rear
  return {
    'rear': rear,
    'front': front,
    'low': 3/4 * ratio,
    'direct': ratio,
    'high': 4/3 * ratio
  }

ratios = [sa_aw_ratio(front) for front in range(34, 46, 2)]

for ratio in ratios:
  fmt_string = "| {front}T | {low:.2f} | {direct:.2f} | {high:.2f} |"
  print(fmt_string.format(**ratio))

print()

def fuji_ratio(rear):
  front = 42
  ratio = front / rear
  return ratio

for rear in [14, 16, 19, 24, 28]:
  ratio = fuji_ratio(rear)
  print(ratio)
