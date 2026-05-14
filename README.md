![](../../workflows/gds/badge.svg) ![](../../workflows/docs/badge.svg) ![](../../workflows/test/badge.svg) ![](../../workflows/fpga/badge.svg)

# Tiny Tapeout Verilog Project: Distributed Computing with Pong!

### Just watch it in action!

<video src="src/debug_history/checkpoint5_unstable_teleport_after_3/checkpoint5.mp4" controls="controls" width="100%">
</video>
[Watch Game Demo](src/debug_history/checkpoint5_unstable_teleport_after_3/checkpoint5.mp4)

### Two chips. One game. No seams.

Two chips frankensteined together to act as one.
* The left chip owns the left half.
* The right chip owns the right half.


They talk through wires and pass the ball back and forth like one seamless chip.

Just like AI data centers split math across thousands of processors, these two chips split a game of Pong – passing ball physics between two screens.

## How It Works

The game field is split across two separate chips.

When the ball reaches the edge of one screen, the active chip pauses it and sends its speed and direction to the second chip.

Once the second chip confirms it received the data, it draws the ball and resumes the movement.

The first chip then deletes its copy of the ball.This handshake happens so fast that the two screens look like one single continuous playing field.

| Connection State | Behavior |
| --- | --- |
| Connected | Ball flows seamlessly left ↔ right |
| Disconnected | Ball bounces off edge like a normal wall |
| Reconnect | Right screen ball disappears, left screen keeps playing |

## Why This Matters?

This project is a visual demonstration of distributed computing — multiple computers working together to solve a single problem.

#### But wait, what is the difference from a normal multiplayer game?

* Most multiplayer games use a central server. If the server crashes, the game ends for everyone

* This project is entirely decentralized. There is no main server. Both chips have equal power, see the exact same game world, and cooperate directly with each other.

* This works like **cryptocurrency** – completely decentralized. Both chips see the same game world and agree on what's happening, stitching their screens into one giant seamless display.

### **The Core Principles**

#### 1. No Central Leader (Be Water)
* Both chips run the exact same code and have equal authority.

* Each chip is fully capable of running its own local environment independently if the connection to its partner is lost.

* One chip failure never takes down the whole system.

#### 2. Parallelism (Like AI Chips)
* Instead of one chip doing all the work, two chips split the job evenly.

* Each chip share real-time results continuously during gameplay.

* This mimics the same principle powering massive AI chips: splitting work across many smaller processors to solve problems no single chip could handle alone.

#### 3. Automated Self-Healing (By Democracy)
* Disconnected chips preserve local game states internally.

* Reconnection triggers automatic data exchange.

* Merged states rebuild and synchronize the shared world.

* System heals completely without requiring a reboot.

&nbsp;

## Made Possible by Tiny Tapeout

This project wouldn't exist without **Tiny Tapeout** – the platform that makes chip design accessible to everyone.

<img src="ChipLayout1.png" width="100%" alt="Chip Layout">
<img src="ChipLayout2.png" width="100%" alt="Chip Layout Zoomed">
<img src="ChipLayout3.png" width="100%" alt="Chip Layout Angle">

### The Backstory: From Zero to Silicon

The author learned about chip design at an amazing workshop hosted by [Pat Deegan](https://www.youtube.com/@PsychogenicTechnologies) at [Latch-Up 2026](https://fossi-foundation.org/latch-up/2026) – a conference dedicated to free and open source silicon by ([FOSSi Foundation](https://fossi-foundation.org/)).

The [Tiny Tapeout](https://tinytapeout.com/) workshop showed that anyone can design and fabricate a chip.

* Inspired by that experience, the author decided to build something wild: distributed computing on a tiny chip. A proof that parallelism and fault tolerance aren't just for AI data centers – they can run on two crappy frankensteined chips playing Pong.

### **From zero to tapeout in 7 days**


**No prior chip design experience.** Just curiosity, and a stubborn belief that it could be done by a nobody.

For the sake of the author's bigger end goal:

>**Project Yeouibu** - a magical charm inscribed with words that manifest your intentions into physical reality, operating exactly like human-commanded semiconductor technology.
>
>* Building a world-class semiconductor empire in the most underrated smartest city in the world, Waterloo Canada
>
>* Turning it into a beacon of global innovation through a special economic zone initiative.
([Article](https://www.linkedin.com/feed/update/urn:li:activity:7440488589068566529/?utm_source=share&utm_medium=member_desktop&rcm=ACoAAD8EX30BDpb0W0uJlx1NSad0ZRf28OHpHgE))
> <br><br>

### **100+ hours of work**

Watching the same sunrise 4 times in the last sprint of the 1 week marathon - **from noobie workshop to tape it out**

The author **self-taught** everything: 

From Distributed Computing, Network Protocols, Signal Processing, Hardware Descriptive Language (HDL), Chip Design, to Game Design. Just by pure thinking!

Fun to learn by doing. Fun to invent solutions from just solving the problem, no terminology, no spoiler. All from pure reasoning.

### If the author can do it, **so can you**.


Whether you want to build AI accelerators, distributed systems, or just play Pong across two chips – Tiny Tapeout is your starting line.

### **Learn. Build. Tape out.**

&nbsp;

# Future Development

#### Many features are planned but couldn't fit due to lack of experience and time. What exists now is the bare minimum – a proof of concept. But the foundation is solid. The potential is huge.


## 1. Scalable Network Chaining with Consensus

The current design supports two chips. The next evolution: **connect as many chips as you want**.

With 8 bidirectional pins, ball and connection status can be condensed into the UART protocol. Each chip can be designed and optimized to talk to all its neighbors using 4 pairs of UART pins.

### Network Topology in TinyTapeOut

<img src="TT07demoboard.jpg" width="100%" alt="Manufactured TinyTapeOut development board">

With 8 bidirectional pins, each chip can talk to all its neighbors using 4 pairs of UART pins. Each chip builds its local network map based on which pin numbers are connected. By summing the connection numbers reported by its neighbors, each chip calculates a **vote**. These votes are broadcast to everyone, allowing the network to assign unique IDs and build a global map.

**Every chip agrees on who holds the ball and how it's passed – just like cryptocurrency!**

### Consensus Voting with Asymmetric Pin Mapping (The Voting Mechanism)

This is the hard part of distributed computing – building trust among chips so they believe what another chip says is true.

Using my game analogy to illustrate: automatic identification as proof-of-concept showcasing how this can be done in modern AI/data center chips.

Given the constraint that every chip shares identical hardware and software, they cannot identify themselves uniquely. UART pair pin numbers can be utilized to create asymmetry for consensus voting.

Each chip follows the connection rule below to connect with every other chip using **its relative pin pair positions**, creating unique vote values.

| Chip | Pair 1-2 | Pair 3-4 | Pair 5-6 | Pair 7-8 |
|------|---------|---------|---------|---------|
| **A** | B | C | D | E |
| **B** | A | C | D | E |
| **C** | A | B | D | E |
| **D** | A | B | C | E |
| **E** | A | B | C | D |

### How Voting Works (Pin Position = Weight)

During booting iteration, each chip declares a vote – the connection pin number – to every other chip in the network.

| Chip | Pair 1-2 | Pair 3-4 | Pair 5-6 | Pair 7-8 |
|------|---------|---------|---------|---------|
| **A** | B = 1 | C = 2 | D = 3 | E = 4 |
| **B** | A = 1 | C = 2 | D = 3 | E = 4 |
| **C** | A = 1 | B = 2 | D = 3 | E = 4 |
| **D** | A = 1 | B = 2 | C = 3 | E = 4 |
| **E** | A = 1 | B = 2 | C = 3 | D = 4 |

In the next iteration, every chip has received votes from all its active connections. Each chip calculates its **vote sum**:

| Chip | Votes from neighbors | Vote Sum |
|------|---------------------|----------|
| A | B(1) + C(1) + D(1) + E(1) | **4** |
| B | A(1) + C(2) + D(2) + E(2) | **7** |
| C | A(2) + B(2) + D(3) + E(3) | **9** |
| D | A(3) + B(3) + C(3) + E(4) | **13** |
| E | A(4) + B(4) + C(4) + D(4) | **16** |

Each chip broadcasts its vote. All chips collect every vote and sort them:

| Vote | Chip | ID |
|------|------|-----|
| 4 | A | 0 (left edge) |
| 7 | B | 1 |
| 9 | C | 2 |
| 13 | D | 3 |
| 16 | E | 4 (right edge) |

*If there is a tie, both chips join together as a team with the same ID – left as an exercise for the player to figure out team formation with port configuration.*

### The Global Map


Now every chip knows:
1. Who it is connected to
2. What its neighbors are connected to
3. Its position in the local network based on the voted sum

When a chip gets disconnected, it can simply repeat the voting process and re-identify itself and its local network following the connection rule as a global source of truth, or just reseated from its missing slot of the local network map for a simplier route.

Player could also optimize all of the voting combination to fit more than 5 chips, left as a logic exercise for the player if they have more than 5 players. The author would be impressed if anyone manages to gather so many people to play it.

**Add more chips. Build a wall. Make a stadium. The game grows with your hardware.**

## 2. ICBM Mechanics

After the infrastructure is done, the next thing is to make the game fun!

As the author spent hefty time and heavily inspired by Maplestory and GregTech (Minecraft mod about real-life industrial processes), the author has been thinking about building a game out of that concept. The next feature: player controls a jet with its own maneuver mechanics. Player can shoot ICBMs with a cooldown to another player's local map through the physics transfer demonstrated in this Pong prototype.

Portals spawn chaotically, indicated by color for connected pairs, where ICBMs are transported from attacker to target dimension (inspired by modern Maplestory boss mechanics). The ICBM bounces indefinitely until it crosses another portal or is destroyed by the player.

If an ICBM is destroyed by another ICBM not originating from that space, it triggers a deadly cross beam (parallel and perpendicular from the destroyed ICBM's trajectory and center), posing danger and penalty to the player. If two ICBMs not originating from local space collide, they form 2 deadly crosses based on the collision direction – introducing chaotic dynamics where players choose between attack and defense. If a player is destroyed, all ICBMs originated by that player disappear until the last man stands.

However, based on the current minimal proof-of-concept code, it already occupies 2 tile spaces from Tiny Tapeout. Implementation is unlikely – the author believes this is enough to demonstrate the distributed computing concept.

&nbsp;


# This Project as Distributed Computing Proof-of-Concept

This silly Pong game is more than just a game. It demonstrates the same principles that power massive AI data centers – scaled down to two tiny chips connected by jumper wires.

| Principle | AI Data Center | This Pong Game |
|-----------|----------------|----------------|
| **Chip-to-chip trust  (Shared State)** | Thousands of GPUs agree on massive weight updates using consensus algorithms like Raft or Paxos to prevent split-brain scenarios | Two chips negotiate who has the real ball |
| **Fault tolerance (Graceful Degradation)** | A single failed node cannot kill a 100-day training run. Frameworks use asynchronous gradient descent or local micro-checkpoints so the rest of the cluster keeps computing | Disconnecting allows local, independent gameplay to continue. |
| **Self-healing (Dynamic Re-Clustering)** | Modern orchestrators use automated hot-swapping and health-check loops. When a node recovers, it automatically pulls the latest state from neighbors and catches up | Reconnecting automatically rebuilds and resynchronizes the game world. |
| **Decentralized consensus (Homogeneous Nodes)** | Scalability relies on massive arrays of identical accelerator nodes. Uniformity ensures predictable latency, deterministic math, and symmetric workloads | Both chips run identical hardware and software. No master. No slave |

What scales from two chips playing Pong scales to ten thousand chips training the next AI. The physics changes. The concept stays the same.

## Beyond a Silly Game: The Future of Chip-to-Chip Communication

If the same principles scale, then the same bottlenecks also scale. Distributed computing relies heavily on chip-to-chip communication. The current bottleneck for AI and data center chips is **power** and the **shoreline** – the physical edge where massive amounts of parallel data enter and exit the chip.

In this game, interconnect between chips is demonstrated through jumper wires between bidirectional pins on a PMOD socket. In real modern chips, high-speed data paths rely on ultra-fine copper traces or optical transceivers – but this has already reached its physical limit.

## Where the Industry is Today

To minimize the physical distance between computation and communication, the industry is transitioning toward **Co-Packaged Optics (CPO)**, which integrates optical routing components directly into the chip package.

<img src="Co-PackagedOptics.jpg" width="100%" alt="Co-Packaging Optics Transition">

> Transition between co-packaging optics, image [*source*](https://www.youtube.com/watch?v=Xt-GY8Pkt6g) [1]


<img src="Co-PackagedOptics2.webp" width="100%" alt="Co-Packaging Optics Roadmap">

> Key trending of co-packaging optics, image [*source*](https://www.idtechex.com/en/research-report/co-packaged-optics-cpo/1138) [2]


The architectural roadmap is clear: **Pluggable modules → ASIC → Direct Substrate Integration**

### The Problem: Neither Copper Nor VCSEL Scales to Sub-TeraHz

To achieve sub-TeraHz data rates, we must evaluate the limitations of the two dominant interconnect technologies used today.

<img src="CoppervsOptics.webp" width="100%" alt="Copper vs Optics Comparison">

> Data center interconnect map, image [*source*](https://www.asteralabs.com/the-400g-per-lane-inflection-point-where-copper-and-optical-meet-in-ai-infrastructure/) [3]

## Copper

While copper is a cost-effective and reliable solution for short-reach signaling, it hits a rigid physical wall at **400G per lane** [3], rendering it incapable of supporting sub-TeraHz frequencies. **Beyond 200G per lane, signal quality degrades exponentially** due to the AC skin effect, As current becomes confined to this thin outer layer, microscopic surface roughness forces it to travel a longer effective path, significantly increasing AC resistance [4].

Even worse, once the signal leaves the die, the plastic packaging and circuit board materials absorb high-frequency energy and turn it into **heat**. At sub-TeraHz speeds, the wires themselves **act like a filter that kills the signal**, or worse, like antennas that broadcast noise everywhere [5]. This is why optical fibers are so attractive: **light has no electrical charge, so signals don't interfere with each other. Copper simply cannot go faster without burning too much power**, needing complex electronics, or turning into a radio transmitter.

## VCSEL

<img src="VCSEL.webp" width="100%" alt="VCSEL">

> VCSEL, img [*source*](https://www.brandnewdiode.com/news/what-is-vcsel-77140908.html) [6]

**VCSELs** (Vertical-Cavity Surface-Emitting Lasers) are the industry standard for optical transceivers. They convert electricity to light using tiny lasers embedded in the chip. But this approach has deep flaws.

**While VCSELs is highly reliable within hot-swappable pluggable modules** [7], integrating VCSELs directly onto a high-performance compute substrate introduces **significant architectural vulnerabilities**. A single laser failure ruins the entire multi-thousand-dollar ASIC package, bricking the entire computation module and cause unacceptable system downtime. Because of this fatal manufacturing and deployment risk**, next-generation infrastructure roadmaps stop short of placing VCSELs directly on the processor die. Instead, **architects keep these optical arrays isolated at the near-ASIC or Near-Package Optics (NPO) boundary** [8].

<img src="BroadcomNPO.jpg" width="100%" alt="Broadcom VCSEL NPO Architecture">

<img src="BroadcomNPO1.png" width="100%" alt="Broadcom VCSEL NPO Architecture">

> Near Packaging Optics (NPO) VCSEL, image [*source*](https://www.broadcom.com/blog/beyond-the-copper-wall-scaling-ai-clusters-with-vcsel-based-near-package-optics-npo-) [8]

<img src="VCSELPrinciple.webp" width="100%" alt="VCSEL Principle">

> VCSEL principle, img [source](https://inphenix.com/vcsel-vertical-cavity-surface-emitting-laser-principles-advantages-applications-and-future-trends/) [9]

Furthermore, the process of direct modulation introduces severe performance bottlenecks at high operational speeds. To encode digital data, the injection current must be cycled rapidly up and down to alter the charge carrier density within the central active layer. This direct injection forces rapid electron-hole recombinations, turning the electrical pump current into an amplified optical signal via stimulated emission. However, rapidly toggling this injection current alters the internal carrier density and localized temperature of the active region, which dynamically shifts the semiconductor’s refractive index. Because the optical length of the cavity changes with the refractive index, the laser cannot maintain a pure color, resulting in severe wavelength chirp. This dynamic color shifting causes the optical pulses to spread out and blur via chromatic dispersion, rapidly degrading signal integrity over fiber runs.

Worse, the physical design required to build these vertical lasers introduces a fundamental RC parasitic bottleneck that prevents fast switching. To bounce light vertically, VCSELs require dozens of alternating, planar Distributed Bragg Reflector (DBR) mirror layers grown parallel to the substrate. Forcing the modulation current to flow vertically through these numerous material interfaces creates high internal series resistance. Simultaneously, to make the laser efficient, the current must be squeezed through a microscopic oxide confinement aperture. Sandwiching this thin insulating oxide layer between highly conductive p-type and n-type semiconductor regions creates a parallel-plate structure that traps a massive amount of parasitic capacitance.

In short, VCSEL suffer **severe wavelength chirp** and **RC parasitic bottlenecks** from their fundamental physics [10], forming a structural low-pass filter that rounds off sharp digital pulses. This restricts them to binary or basic PAM4 signaling, capping single-lane speeds in **200Gb/s PAM4** [11], well below the sub-TeraHz data rates required by next-generation links. Structurally, because VCSELs consist of alternating, planar DBR mirrors grown parallel to the substrate, they emit light vertically. This vertical profile prevents them from cleanly coupling into flat, planar photonic waveguides without complex, high-loss 90-degree turning mirrors. This geometric mismatch, combined with their **inability to support high-density Wavelength Division Multiplexing (WDM) in a single bus waveguide** [12], establishes VCSELs as an **inadequate, short range solution**.

**If anyone wants to build the next generation of interconnect, photonics is not an option – it becomes a necessity. But VCSELs are not the answer.**

# The Author's Research

This project went from a workshop concept to final tapeout in a single, intense one‑week sprint from nothing. Far from an end goal, this milestone represents a beginning. It let the author get hands-on experience building optical communication, from simple jumper wires to photonics, with the ultimate goal of building a substrate-level optical transceiver capable of **revamping the backbone of chip communication.**

Instead of embedding lasers inside the chip, my research moves the light source **off-chip** using an **external frequency comb** delivers light to the substrate via **photonic wire bonding**. The optical signal is then routed directly to an on-chip array of **Microring Resonators** (MRRs), which are made of **non-linear optical materials** like **Thin Film Lithium Niobate (TFLN)** and **Barium Titanate Oxide (BTO)** - explained in the process.

<img src="MicroringResonatorOpticalTransceiver.png" width="100%" alt="Microring Resonator Optical Transceiver Design">

> Author proposed design, img [source](https://arxiv.org/abs/2506.12962) [13]

### The Physics: Why Pockels Effect Beats Laser Modulation

Traditional VCSELs work by turning a laser on and off as fast as possible. But switching a laser on and off has hard limits – it is slow, generates heat, and eventually cannot go any faster.

<img src="EvanscentCoupling.jpg" width="100%" alt="Evanscent Coupling">

> Evanscent coupling, video [source](https://www.youtube.com/watch?v=4O-1CJx4s4w) [14]

This design takes a completely different approach. It uses **evanescent coupling** between MRRs to capture the optical signal from the bus waveguide through resonance [15]. The ring is designed to be exactly the right size so that light of a specific wavelength resonates inside it, bouncing around thousands of times.

> [Full video of Evanscent coupling between straight waveguide and a microring resonator](https://www.youtube.com/watch?v=_OlW0hP9rX8) [16]

<video src="1StraightWaveguide1MRR.mp4" controls="controls" width="100%">
</video>
[Watch Video](1StraightWaveguide1MRR.mp4)

> Resonance between straight waveguide and a microring resonator, video [source](https://www.comsol.com/blogs/calculating-the-spectral-properties-of-an-optical-ring-resonator) [17]


When the ring resonates, it traps that wavelength. Light does not pass through the bus waveguide, representing an "off" state.

To modulate this signal, a localized voltage is applied across the ring's non-linear optical cladding [19]. This triggers the linear electro-optic (Pockels) effect [20], which instantaneously alters the material's refractive index. Changing the refractive index alters the effective optical path length of the ring. This shifts the microring's resonance frequency away from the laser’s wavelength, breaking the coupling condition. The light no longer enters the ring and instead travels unhindered down the bus waveguide — representing an "on" state.

<img src="MicroringResonatorLogic.webp" width="100%" alt="Microring Resonator Logic">

> Toggling optical channel signal with microring resonator, img [source](https://ayarlabs.com/glossary/micro-ring-resonators/) [21]

The key is that this voltage-driven index change happens in **picoseconds** – a thousand times faster than a nanosecond. Pure electrical control of light, ready to be exploited to develop the next generation of optical transceivers.

This is the breakthrough that enables sub‑TeraHz modulation.

### The Design: External Frequency Comb + MRR Array

Instead of embedding lasers on-chip, a single external frequency comb produces many wavelengths simultaneously. Here is how it works.


<video src="MicroringResonatorVideo.mp4" controls="controls" width="100%">
</video>
[Watch Video](MicroringResonatorVideo.mp4)

> Laser injection to chip scale MRR, video [source](https://actu.epfl.ch/news/a-micro-ring-resonator-with-big-potential-5/) [22]

1. Injection: the frequency comb injects a C‑band (capable of long-distance transfer) with regularly spaced spectral lines into a single bus waveguide via photonic wirebonding. Each discrete spectral line serves as an independent data channel.

2. Modulation: an array of MRRs sits alongside the shared waveguide, with each individual ring tuned to resonate with one specific wavelength from the comb. When no voltage is applied, the MRR resonates at that frequency and blocks the light – a logical 0. When voltage is applied to trigger the Pockels effect, the resonance frequency shifts and light passes through – a logical 1.

3. Parallel Multiplexing: The independently modulated, multi-coloured data channels travel concurrently down the single, shared waveguide across the chip, board, or server rack.

4. Demodulation: A matching receiver array of MRRs, paired with integrated high-speed photodetectors, filters and reads each wavelength channel in parallel.

By leveraging the Pockels effect, the resonance frequency shifts deliberately to mismatch the optical channel wavelength – allowing transmission. This enables signals to be densely packed within a single bus waveguide, unlocking parallel, low-latency data routing across chips, boards, and racks.

### The Materials: TFLN and BTO

For the photonic layer of the MRR array, the industry have been developing two kind of nonlinear optical materials.

**Thin Film Lithium Niobate (TFLN)** is mature, silicon‑compatible, and thermally conductive. It has an excellent Pockels coefficient and helps remove heat from the CMOS driver.

**Barium Titanate Oxide (BTO)** While still primarily in the research and development phase, BTO offers a significantly higher Pockels coefficient than TFLN, delivering unmatched energy efficiency for electro-optic conversion.

Both are excellent candidates for sub‑THz communication. The fabrication challenge, specifically etching uniformity and high-quality thin-film deposition remain persistent [22]. But that is the opportunity, not the obstacle.

### Integration: Photonic Layer on CMOS BEOL

The photonic layer is wafer‑bonded directly to the Back‑End‑of‑Line (BEOL) of the CMOS driver/receiver die. This integration achieves several things.

The non-linear photonic layer is wafer-bonded directly to the Back-End-of-Line (BEOL) layers of the CMOS driver and receiver die. This monolithic integration achieves several critical design goals:

<img src="EPIC.jpeg" width="100%" alt="Electronic and Photonic Integrated Circuit">

> Monolithic integration of Electronic and Photonic Integrated Circuit, img [source](https://photonicsreport.com/blog/the-fascinating-relationship-between-photonics-and-electronics/) [23]

Thermal Isolation: Thermal energy from the primary light source never enters the compute die, confining on-chip thermal dissipation strictly to the CMOS logic itself—which is further mitigated by TFLN’s high thermal conductivity.

Zero Laser Dead-Time: – The laser stays on continuously. No waiting for it to turn on and off. Switching happens entirely through voltage, not laser cycling.

Elimination of Single-Point Failures: Shifting the active laser cavities off-chip ensures the multi-wavelength comb source remains entirely hot-swappable and field-replaceable.

True Optical Parallelism: Multiple optical channels signal propagate simultaneously through a single waveguide. Because the routing architecture relies entirely on passive evanescent coupling inside a microring rather than destructive electrical manipulation, the multi-wavelength bus waveguide can be routed freely across the system architecture without significant risk of signal degradation or of material breakdown.

## The Vision

This design delivers **superior communication infrastructure** compared to VCSEL and pure electrical signaling.

A vertically integrated **Electronic‑Photonic Integrated Circuit (EPIC)** fab is a worthwhile investment in today's technology landscape. These architectures are gaining increasing attention in both academia and industry – and they represent the only path forward for sub‑TeraHz data transfer.

---

### A Word from the Author

The author has been working on this project alone and has run into many life challenges. Nobody believed a "nobody" and also would be crazy enough to attempt for a fight for world-class semiconductor empire. So the author bit the bullet and tanked the losses.

This silly Pong game? It's a stupid prototype. A desperate attempt to prove that this could work. To convince people that one person who have nothing to do in life but with an ambition and 100+ hours within a week can make something real.

**If you're interested – even just curious – I'd love to chat.**
Connect with me on [LinkedIn](https://www.linkedin.com/in/timllh/).

#### Author's Current Task list

| Task | Status |
|------|--------|
| Athermal MRR Array Simulation and Optimization | On Hold |
| 7nm CMOS FinFET Process CAD Modeling | On Hold |
| DRAM Process CAD Modeling (Co-Developing In-Game DRAM Process Recipes for [SuperSymmetry](https://susymodpack.substack.com/p/3-circuit-overhaul)) | Work in Progress |
| Complete Circuit Design for the EPIC | On Hold |
| Develop Minimal Viable Layout Schematics of the EPIC | On Hold |
| [**2026 Chipathon**](https://sscs.ieee.org/technical-committees/tc-ose/sscs-pico-design-contest/) | Current next task |

---

### References

1. "Co-Packaged Optics for our Connected Future," YouTube, 2024. [Online Video]. Available: [Youtube](https://www.youtube.com/watch?v=Xt-GY8Pkt6g)

2. Y. H. Chang, "Co-Packaged Optics (CPO) 2026-2036: Technologies, Market, and Forecasts," IDTechEx, Research Report, 2025. [Online]. Available: [IDTechEx](https://www.idtechex.com/en/research-report/co-packaged-optics-cpo/1138)

3. C. Blackburn, "The 400G-Per-Lane Inflection Point: Where Copper and Optical Meet in AI Infrastructure," Astera Labs, Tech. Rep., 2024. [Online]. Available: [Astera Labs](https://www.asteralabs.com/the-400g-per-lane-inflection-point-where-copper-and-optical-meet-in-ai-infrastructure/)

4. F. Alawneh, "Futuring Interconnect Infrastructure for AI: RF Transmission over Plastic Cable Surpasses Copper and Optics at Terabit Scale," Signal Integrity Journal, June 2024. [Online]. Available: [Signal Integrity Journal](https://www.signalintegrityjournal.com/articles/4011-futuring-interconnect-infrastructure-for-ai-rf-transmission-over-plastic-cable-surpasses-copper-and-optics-at-terabit-scale).

5. X. Zhou, L. Zhang, and T. Wang, "Co-Design of Thermal and RF Performance in a Stacked Sub-THz Antenna-in-Package With Embedded Endfire Arrays," IEEE Transactions on Components, Packaging and Manufacturing Technology, vol. 16, no. 2, pp. 210-219, Feb. 2026. doi: [10.1109/TMTT.2025.3619939](https://doi.org/10.1109/TMTT.2025.3619939)

6. "What Is VCSEL?," Hangzhou Brandnew Technology Co., Ltd., Apr. 2024. [Online]. Available: [Hangzhou Brandnew Technology](https://www.brandnewdiode.com/news/what-is-vcsel-77140908.html)

7. "The VCSEL Advantage: Increased Power, Efficiency, and Reliability," Photonics Spectra, Photonics Media, 2025. [Online]. Available: [Photonics Media](https://www.photonics.com/Articles/The-VCSEL-Advantage-Increased-Power-Efficiency/a25102)

8. Broadcom Inc., "Beyond the Copper Wall: Scaling AI Clusters with VCSEL-Based Near-Package Optics (NPO)," Broadcom Blog, 2024. [Online]. Available: [Broadcom](https://www.broadcom.com/blog/beyond-the-copper-wall-scaling-ai-clusters-with-vcsel-based-near-package-optics-npo-)

9. "VCSEL Principles and Future Trends Explained," InPhenix Knowledge Base, Dec. 2025. [Online]. Available: [InPhenix Knowledge Base](https://inphenix.com/vcsel-vertical-cavity-surface-emitting-laser-principles-advantages-applications-and-future-trends/)

10. Irrational Analysis, "Practical Datacom Lasers," Irrational Analysis Substack, Jan. 24, 2026. [Online]. Available: [Irrational Analysis](https://irrationalanalysis.substack.com/p/practical-datacom-lasers)

11. F. Koyama, H. Ibrahim, A. Hassan, and X. Gu, "Pushing the limits of VCSEL technology: >200 Gb/s 1060-nm single-mode VCSEL array for next-generation SMF/MMF interconnects," in Proc. SPIE PC13911, Vertical-Cavity Surface-Emitting Lasers XXX, PC1391107, Mar. 2026. doi: [10.1117/12.3089572](https://doi.org/10.1117/12.3089572)

12. M. Karppinen, "VCSEL Techniques for Wavelength-Multiplexed Optical Interconnects," Chalmers University of Technology, Gothenburg, Sweden, Tech. Rep. 511930, 2024. [Online]. Available: [Chalmers University of Technology](https://research.chalmers.se/publication/511930)

13. D. Saiham, D. Wu, and S. Rahman, "Leveraging photonic interconnects for scalable and efficient fully homomorphic encryption," arXiv preprint arXiv:2506.12962, 2025. [Online]. Available: [arXiv](https://arxiv.org/abs/2506.12962)

14. "Silicon Photonics Micro-Ring Resonators," YouTube, 2021. [Online Video]. Available: [Youtube](https://www.youtube.com/watch?v=4O-1CJx4s4w)

15. D. G. Rabus, Integrated Ring Resonators: The Compendium, Springer Series in Optical Sciences, vol. 127. Berlin, Heidelberg: Springer, 2007. [Online]. Available: [Springer](https://link.springer.com/book/10.1007/978-3-540-68788-7)

16. "Ring Resonator Simulated in Lumerical MODE Solutions' Propagator," YouTube, 2021. [Online Video]. Available: [Youtube](https://www.youtube.com/watch?v=_OlW0hP9rX8)

17. S. Obeidat, "Calculating the Spectral Properties of an Optical Ring Resonator," COMSOL Blog, Jan. 30, 2024. [Online]. Available: [COMSOL Blog](https://www.comsol.com/blogs/calculating-the-spectral-properties-of-an-optical-ring-resonator)

18. J. Ling, Y. He, R. Luo, M. Li, H. Liang, and Q. Lin, "Athermal lithium niobate microresonator," Optics Express, vol. 28, no. 15, pp. 21682-21691, Jul. 2020. [Online]. Available: doi: [10.1364/OE.398363](https://doi.org/10.1364/OE.398363)

19. Y. Li, M. Sun, T. Miao, and J. Chen, "Towards High-Performance Pockels Effect-Based Modulators: Review and Projections," Micromachines, vol. 15, no. 7, p. 865, Jun. 2024. [Online]. Available: doi : [10.3390/mi15070865](https://doi.org/10.3390/mi15070865)

20. "Micro-Ring Resonators (MRRs)," Ayar Labs Glossary, 2026. [Online]. Available: [Ayar Labs](https://ayarlabs.com/glossary/micro-ring-resonators/)

21. S. Benmachiche, "A micro-ring resonator with big potential," EPFL News, Apr. 08, 2026. [Online]. Available: [EPFL News](https://actu.epfl.ch/news/a-micro-ring-resonator-with-big-potential-5/)

22. Y. Wen, H. Chen, Z. Wu, W. Li, and Y. Zhang, "Fabrication and photonic applications of Si-integrated LiNbO3 and BaTiO3 ferroelectric thin films," APL Materials, vol. 12, no. 2, p. 020601, Feb. 2024. doi: 10.1063/5.0192018. [Online]. Available: [APL Materials](https://pubs.aip.org/aip/apm/article/12/2/020601/3262490/Fabrication-and-photonic-applications-of-Si)

23. "The fascinating relationship between photonics and electronics: Photonic and electronic circuits," Photonics Report, Dec. 17, 2024. [Online]. Available: [Photonics Report](https://photonicsreport.com/blog/the-fascinating-relationship-between-photonics-and-electronics/)

## What is Tiny Tapeout?

Tiny Tapeout is an educational project that aims to make it easier and cheaper than ever to get your digital and analog designs manufactured on a real chip.

To learn more and get started, visit https://tinytapeout.com.

## Set up your Verilog project

1. Add your Verilog files to the `src` folder.
2. Edit the [info.yaml](info.yaml) and update information about your project, paying special attention to the `source_files` and `top_module` properties. If you are upgrading an existing Tiny Tapeout project, check out our [online info.yaml migration tool](https://tinytapeout.github.io/tt-yaml-upgrade-tool/).
3. Edit [docs/info.md](docs/info.md) and add a description of your project.
4. Adapt the testbench to your design. See [test/README.md](test/README.md) for more information.

The GitHub action will automatically build the ASIC files using [LibreLane](https://www.zerotoasiccourse.com/terminology/librelane/).

## Enable GitHub actions to build the results page

- [Enabling GitHub Pages](https://tinytapeout.com/faq/#my-github-action-is-failing-on-the-pages-part)

## Resources

- [FAQ](https://tinytapeout.com/faq/)
- [Digital design lessons](https://tinytapeout.com/digital_design/)
- [Learn how semiconductors work](https://tinytapeout.com/siliwiz/)
- [Join the community](https://tinytapeout.com/discord)
- [Build your design locally](https://www.tinytapeout.com/guides/local-hardening/)

## What next?

- [Submit your design to the next shuttle](https://app.tinytapeout.com/).
- Edit [this README](README.md) and explain your design, how it works, and how to test it.
- Share your project on your social network of choice:
  - LinkedIn [#tinytapeout](https://www.linkedin.com/search/results/content/?keywords=%23tinytapeout) [@TinyTapeout](https://www.linkedin.com/company/100708654/)
  - Mastodon [#tinytapeout](https://chaos.social/tags/tinytapeout) [@matthewvenn](https://chaos.social/@matthewvenn)
  - X (formerly Twitter) [#tinytapeout](https://twitter.com/hashtag/tinytapeout) [@tinytapeout](https://twitter.com/tinytapeout)
  - Bluesky [@tinytapeout.com](https://bsky.app/profile/tinytapeout.com)
