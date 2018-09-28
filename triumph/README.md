# Triumph

I'm rebuilding an old Triumph / Raleigh bike from the frame up.

## Dating

As far as I know, the frame dates roughly back to the mid 1960s.
Could be as early as the 1950s.
More details pending.

Triumph is an old British brand - the very same as the Triump motorcycle company.
Started in 1884, Triumph traded, built, and sold bicycles up through the end of the second world war.
In 1954 the brand was sold to Raleigh, after which bicycles produced with a Triumph logo were built in the Raleigh Nottingham factory.


## Measurements

* front fork dropout spacing: 90mm
* rear dropout spacing: 114mm
* seatpost length: 21mm
* bottom bracket shell: 71mm
* new bottom bracket spindle: 128mm
* new bottom bracket bearings: 6mm (at the recommendation of Sheldon Brown)

## Final budget

| component   | price |
| ---------   | ----- |
| frame       | $80   |
| bb lockring | $5    |
| bb spindle  | $20   |
| dyno hub    | $45   |
| rear hub    | $33   |
| ---------   | ----- |
| **total**   | $183  |

## Original condition

I initially found the frame posted on Craigslist somewhere out in Fairfax.
When I picked it up, the black matte frame was pretty well stripped down.
No wheels or saddle and just a few of the original components in pretty shoddy condition:

* Handle bars.
These are 'north road' style bars, in pretty decent condition.
There's a little bit of aesthetic surface rust near the clamp point toward the center of the bars, but nothing significant.

* Headset.
No aesthetic damage at all, but the fork could barely rotate freely in the headset.

* Front fork.
The original front fork was still installed when I picked it up and in pretty solid condition.

* Bottom bracket.
Like the headset, the cup and bearing style bottom bracket was almost seized when I got it.
It could barely rotate freely and made a terrible noise.

* Cranks.
The original cottered crank arms came attached to the bottom bracket.

* Pedals.
I don't think these pedals were original, or if they were then the bike is possibly a more recent model than I initially thought.
The pedals are non-rebuildable rubber block pedals labelled as manufactured in Germany.

* Seat post. No saddle.

There is some work ahead of me.

## Restoring / replacing the original components

### Headset & Fork

The first thing I did was disassemble and clean all of the original components.
The bars and headset were straightforward to tear down and clean (this was my first time rebuilding a headset).
After some new grease, the fork turns like a dream.

### Bottom Bracket

The bottom bracket was something of a bear to free up because of the old cottered cranks.
I was able to hammer one cotter pin free immediately, but the head of the non-drivetrain side pin mushroomed out immediately and refused to budge.
To remove the bracket with one crank arm still attached, I ended up cross threading the lock ring onto the adjustable cup and slowly rotating it free.
With the bracket cups and axle free, I was able to drill out the remaining cotter pin to free up the axle and bracket cups.

Because I intend to upgrade to cotterless cranks, the bracket spindle (axle) needed to be replaced as well.
At the [sage advice](https://www.sheldonbrown.com/raleigh26.html) of Sheldon Brown, I was able to find a JIS format square tapered spindle that fit in the original cups with slightly oversized 6mm bearings.
The width of the spindle relative to the frame and the chainstays looks good, but we'll see how the chainline looks when I get a chain ring on.

### Front Wheel

I picked up an old 1955 Sturmey Archer Dynamo hub for the front.
Given the spacing I expect the old hub to be compatible, as this frame most likely originally ran the same (or a similar) hub when it was new.

I picked up an original 1955 Sturmey Archer 32h front dynamo hub.
Will need to thread the spokes and find a rim to match.


### Drivetrain

#### Rear Hub

I picked up a 1964 Sturmey Archer AW three speed 36h internally geared hub for the rear.
It is in almost mint condition.
The sprocket is 18T and 1/8th" width, so fortunately a modern standard size for a single speed chain.

#### Gearing Ratios

I don't want to add a front derailleur so I going to run a 1x front crank.
This will also be more true to the original bike (3-speed would have been the original gearing).
This does, however, mean I need to be intentional when I select my front chainring, since there will be such limited range.

The rear 3 speed offers a 3/4 low gear and 4/3 high gear ratio with direct drive in the middle.
I wrote a quick python script to compute the resulting ratios given various chainrings.

```python
def sa_aw_ratio(front):
  rear = 18 # 18T rear cog
  ratio = front / rear
  return {
    'rear': rear,
    'front': front,
    'low': 2/3 * ratio,
    'direct': ratio,
    'high': 4/3 * ratio
  }
```

| chainring | low  | mid  | high |
| --------- | ---- | ---- | ---- |
| 34T       | 1.42 | 1.89 | 2.52 |
| 36T       | 1.50 | 2.00 | 2.67 |
| 38T       | 1.58 | 2.11 | 2.81 |
| 40T       | 1.67 | 2.22 | 2.96 |
| 42T       | 1.75 | 2.33 | 3.11 |
| 44T       | 1.83 | 2.44 | 3.26 |

Reference gearing ratios from my current 5 speed road bike.

| low | mid  | high |
| --- | ---- | ---- |
| 1.5 | 2.21 | 3.0  |

These are pure ratios, not gear inches, as I am not factoring in the size of the wheel since I don't have rims yet.

The direct drive ratio I'm looking for is around 2.20, so anything between 38-42T would probably do.
Given the nature of the riding I intend to do on this bike, I will probably want to tend toward a lower gearing (but maybe not as low a 2.11 with 38T).

I think 40T will be the size I go with.

#### Chainring


#### Crank arms

### Saddle


