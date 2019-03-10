# Triumph

I'm rebuilding an old Triumph / Raleigh bike from the frame up.

## Final Build

* 1960s Triumph roadster frame in matte black
* wheelset
  * Sturmey Archer GH6 6V DC front dynohub
  * Sturmey Archer AW internally geared rear hub
  * Straight gauge stainless steel spokes
  * Velo Orange 700c PBP polished aluminum box rims
  * Schwalbe Marathon Plus smart guard RLX clincher tires
* drivetrain
  * FSA Gimondi track crankset 170mm arms
  * original no name made in Germany rubber block pedals
  * KMC single speed silver/black chain
* seat
  * original steel seatpost
  * Brooks cambium all-weather saddle, black
* cockpit
  * Velo Orange Porteur handlebars, 22.2mm grips
  * Nitto 100cm aluminum quill stem, 25.4mm clamp
  * Fizik endurance microtex bar tape, black
  * Sturmey Archer 3 speed classic trigger shifter
  * Dia Compe DC-189 reverse brake levers, black aluminum
  * Crane E-ne matte black aluminum bell
* lighting
  * Busch and Müller IQ XS LED dyno front lamp (pending)
  * Busch and Müller VIEW LED dyno taillight (pending)
* fenders
  * Velo Orange polished aluminum full fenders (pending)
* rack
  * (pending)

## Dating

As far as I know, the frame dates roughly back to the mid 1960s.
Could be as early as the 1950s.
More details pending.

Triumph is an old British brand - the very same as the Triump motorcycle company.
Started in 1884, Triumph traded, built, and sold bicycles up through the end of the second world war.
In 1954 the brand was sold to Raleigh, after which bicycles produced with a Triumph logo were built in the Raleigh Nottingham factory.


## Measurements

| label | measurement |
| ----- | ----------- |
| fork dropout spacing | 90mm |
| rear dropout spacing | 114mm |
| seatpost length | 21mm |
| bb shell | 71mm |
| new bb spindle | 128mm |
| new bb bearings | 6mm |
| seat tube diameter | 28.6mm |

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
After some new grease, the steer tube turns like a dream.

### Bottom Bracket

The bottom bracket was something of a bear to free up because of the old cottered cranks.
I was able to hammer one cotter pin free immediately, but the head of the non-drivetrain side pin mushroomed out immediately and refused to budge.
To remove the bracket with one crank arm still attached, I ended up cross threading the lock ring onto the adjustable cup and slowly rotating it free.
With the bracket cups and axle free, I was able to drill out the remaining cotter pin to free up the axle and bracket cups.

Because I intend to upgrade to cotterless cranks, the bracket spindle (axle) needed to be replaced as well.
At the [sage advice](https://www.sheldonbrown.com/raleigh26.html) of Sheldon Brown, I was able to find a JIS format square tapered spindle that fit in the original cups with slightly oversized 6mm bearings.
The width of the spindle relative to the frame and the chainstays looks good, but we'll see how the chainline looks when I get a chain ring on.

The first bottom bracket spindle I purchased was a 7-series JIS 73x128mm spindle.
Its front chainline is 56.7mm, which is a little too wide, but workable.

### Drivetrain

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
| 36T       | 1.50 | 2.00 | 2.67 |
| 37T       | 1.54 | 2.06 | 2.74 |
| 38T       | 1.58 | 2.11 | 2.81 |
| 39T       | 1.62 | 2.17 | 2.89 |
| 40T       | 1.67 | 2.22 | 2.96 |
| 41T       | 1.71 | 2.28 | 3.04 |
| 42T       | 1.75 | 2.33 | 3.11 |
| 43T       | 1.79 | 2.39 | 3.19 |
| 44T       | 1.83 | 2.44 | 3.26 |
| 45T       | 1.88 | 2.50 | 3.33 |

Reference gearing ratios from my current 5 speed road bike.

| low | mid  | high |
| --- | ---- | ---- |
| 1.5 | 2.21 | 3.0  |

These are pure ratios, not gear inches, as I am not factoring in the size of the wheel since I don't have rims yet.

The direct drive ratio I'm looking for is around 2.20, so anything between 38-42T would probably do.
Given the nature of the riding I intend to do on this bike, I will probably want to tend toward a lower gearing (but maybe not as low a 2.11 with 38T).

I think 40T will be the size I go with.

#### Chainring

I purchased a Vuelta SE 130mm 40T aluminum chainring.
It's not as shiny as I would like (Surly's stainless chainring looks amazing) but it'll do.
Still need to select crankarms to toss them on.

#### Crank arms

TBD.

#### Chainline

##### Rear

```
chainline = (.5) * O.L.D. - distance from sprocket to driveside locknut
          = (.5) * (110mm) - (16mm)
          = 39mm
```

##### Front

```
chainline = chainring to seat tube + (.5) * seat tube diameter
          = X + (.5) * 28.6mm
          = X + 14.3mm
```

I want my front chainline to match my rear chainline.
So, I need to come up with the distance my chainring needs to lie from my seat tube (`X` mm).

```
rear chainline = front chainline
39mm = X + 14.3mm
X = 24.7mm
```

The first bottom bracket spindle I bought provides a real `X` value of 42mm.
This is 17.3mm too large.

The bottom bracket spindle 128mm.
The way the frame and crank arms are positioned, I have an absolute maximum of 10mm I could shorten the spindle by before the crank arm rubs against the bracket shell body.
By switching the chainring to the inside of the crank arm I could trim an additional 6mm off.
A 10mm shorter spindle and 6mm less by moving the chainring would get me almost the 17mm I need.
To reduce the drive side of the spindle by 10mm I will need to find a spindle that's `128 - 10 * 2 = 108`mm.
In the interest of not trying my luck too much, anything between 108-113mm is probably going to be fine.

### Saddle

I'm using a Brooks cambium all weather black saddle to match the frame and components.

### Wheelbuilding

#### Front hub

I picked up an original 1955 Sturmey Archer 32h GH6 Dynamo hub for the front.

| distance | measurement |
| ------ | ---- |
| O.L.D. | 90mm |
| Left flange diameter | 42mm |
| Left locknut to flange | 14mm |
| Left flange offset | 33mm |
| Right flange diameter | 102mm |
| Right locknut to flange | 21mm |
| Right flange offset | 26mm |

#### Rear hub

I picked up a 1964 Sturmey Archer AW three speed 36h internally geared hub for the rear.
It is in almost mint condition.
The sprocket is 18T and 1/8th" width, so fortunately a modern standard size for a single speed chain.

| distance | measurement |
| ------ | ---- |
| O.L.D. | 110mm |
| n.d. Locknut to Flange | 25mm |
| d.s. Locknut to Flange | 29mm |
| Flange diameter | 65mm |
| Sprocket to locknut | 16mm |

#### Rim measurements

I'm using the Velo Orange PBP polished square rims.

| distance | measurement |
| -------- | ----------- |
| ERD | 606mm |
| OSB | 0mm |
| Size | 700c |
| Front Spokes | 32h |
| Rear Spokes | 36h |

#### Spokes

Using the [prowheelbuilder.com spoke calculator](https://www.prowheelbuilder.com/spokelengthcalculator), the total spoke count comes out to:

| length | count |
| ------ | ----- |
| 296mm (front left)  | 16    |
| 287mm (front right) | 16    |
| 288mm (rear) | 36    |

Placed an order with my LBS for the spokes.
They cut their own in shop -- fancy.

##### Additional resources
* [Prowheelbuilder.com](https://www.prowheelbuilder.com/spokelengthcalculator)
* [Edd](https://leonard.io/edd/)
* [Spocalc](https://www.sheldonbrown.com/rinard/spocalc.htm)
* [SpokeV2](http://www.mrrabbit.net/wheelsbyflemingapplications.php)

### Cockpit

I went with [Velo Orange's Porteur handlebars](https://velo-orange.com/collections/handlebars/products/vo-porteur-bar-config) and a 100cm nitto quill stem.
I had to use the MTB-style 22.2 mm bars to allow for the classic Sturmey Archer 3-speed shifter strap to fit.

For brake levers, Dia Compe DC-189 reverse levers in black.
The brake lever and body are black aluminum.
