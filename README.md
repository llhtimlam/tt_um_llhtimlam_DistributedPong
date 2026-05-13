![](../../workflows/gds/badge.svg) ![](../../workflows/docs/badge.svg) ![](../../workflows/test/badge.svg) ![](../../workflows/fpga/badge.svg)

# Tiny Tapeout Verilog Project

## Distributed Computing with Pong!

**Two chips. One game. No seams.**

Two chips Frankensteined together to act as one. The left chip owns the left half. The right chip owns the right half. They talk through wires and pass the ball back and forth like one seamless chip.

Just like AI data centers split math across thousands of processors, these two chips split a game of Pong – passing ball physics between two screens.

---

## How It Works

| Connection State | What Happens |
|-----------------|---------------|
| Two chips connected | Ball flows seamlessly left ↔ right |
| One chip alone | Ball bounces off edge like a normal wall |
| Reconnect | Right screen ball disappears, left screen keeps playing |

---

## Why This Matters?

This is distributed computing in action – multiple computers working together on one task.

**But wait, what is the different from a normal multiplayer game?**

Most multiplayer games use a **server-client model** – one central server controls everything. Server dies? Game over for everyone.

This works like **cryptocurrency** – completely decentralized. Both chips see the same game world and agree on what's happening, stitching their screens into one giant seamless display.

- No master. No slave. No single point of failure.
- Both chips run the exact same design. Both are equals.
- One chip dies? The other keeps playing alone.
- Reconnect? They rebuild the world automatically.
- Both alive? They play together as one seamless system.

**Two chips, one world. No boss. No server. Just cooperation.**

Instead of one chip doing all the work, two chips split the job, share results, and keep playing – even when parts fail. This is the same principle powering massive AI chips: **parallelism**. Splitting work across many smaller processors to solve problems no single chip could handle alone.

But here's the real kicker: **self-healing**. One chip dies? The other keeps playing. No crash. No reset. It just works. Reconnect the dead chip? They rebuild the world and resync instantly. No manual intervention. No restart. The system heals itself.

That's fault tolerance. That's distributed computing. Pong just makes it fun to watch.

**Just watch it in action!**

<video src="src\debug_history\checkpoint5_unstable_teleport_after_3\checkpoint5.mp4" controls width="100%">
  Your browser does not support the video tag.
</video>

## Made Possible by Tiny Tapeout

This project wouldn't exist without **Tiny Tapeout** – the platform that makes chip design accessible to everyone.

The author learned about chip design at an amazing workshop hosted by **Pat Deegan** at [Latch-Up 2026](https://fossi-foundation.org/latch-up/2026) – a conference dedicated to free and open source silicon ([FOSSi Foundation](https://fossi-foundation.org/)). The [Tiny Tapeout](https://tinytapeout.com/) workshop showed that anyone can design and fabricate a chip.

Inspired by that experience, the author decided to build something wild: distributed computing on a tiny chip. A proof that parallelism and fault tolerance aren't just for AI data centers – they can run on two Frankensteined chips playing Pong.

**From zero to tapeout in 7 days.**

**No prior chip design experience.** Just curiosity, and a stubborn belief that it could be done by a nobody, for the sake of the author's bigger end goal, Project Yeouibu: **building a world-class semiconductor empire in the most underrated smartest city in the world, Waterloo Canada, north of his favourite dorm, Columbia Lake Village (CLV) – turning it into a beacon of global innovation through a special economic zone initiative.**
([Article about the special economic zone initiative] (https://www.linkedin.com/feed/update/urn:li:activity:7440488589068566529/?utm_source=share&utm_medium=member_desktop&rcm=ACoAAD8EX30BDpb0W0uJlx1NSad0ZRf28OHpHgE))

**100+ hours of work, and watching the same sunrise 4 times in the last sprint of the marathon** – from workshop to taping it out

If the author can do it, **so can you**.

Whether you want to build AI accelerators, distributed systems, or just play Pong across two chips – Tiny Tapeout is your starting line.

**Learn. Build. Tape out.**

## Future Development

This project was built in **1 week** with no prior background. The author self-taught everything: distributed computing, network protocols, signal processing, hardware design, HDL, chip design, and game engineering.

Many features are planned but couldn't fit due to lack of experience and time. What exists now is the bare minimum – a proof of concept. But the foundation is solid. The potential is huge.

**Fun to learn by doing. Fun to invent solutions from pure thinking.**

## Planned Features

## Scalable Network Chaining with Consensus

The current design supports two chips. The next evolution: **connect as many chips as you want**.

With 8 bidirectional pins, ball and connection status can be condensed into the UART protocol. Each chip can be designed and optimized to talk to all its neighbors using 4 pairs of UART pins.

---

## Network Topology in TinyTapeOut

<img src="TT07 demoboard.jpg" width="100%" alt="Manufactured TinyTapeOut development board">

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
| C | A(1) + B(2) + D(3) + E(3) | **9** |
| D | A(1) + B(2) + C(3) + E(4) | **10** |
| E | A(1) + B(2) + C(3) + D(4) | **10** |

Each chip broadcasts its vote. All chips collect every vote and sort them:

| Vote | Chip | ID |
|------|------|-----|
| 4 | A | 0 (left edge) |
| 7 | B | 1 |
| 9 | C | 2 |
| 10 | D | 3 |
| 10 | E | 4 (right edge) |

*If there is a tie, both chips join together as a team with the same ID – left as an exercise for the player to figure out team formation with port configuration.*

### The Global Map

Now every chip knows:
- Who it is connected to
- What its neighbors are connected to
- Its position in the local network based on the voted sum

When a chip gets disconnected, it can simply repeat the voting process and re-identify itself and its local network following the connection rule as a global source of truth, or just reseated from its missing slot of the local network map for a simplier route.

Player could also optimize all of the voting combination to fit more than 5 chips, left as a logic exercise for the player if they have more than 5 players. The author would be impressed if anyone manages to gather so many people to play it.

**Add more chips. Build a wall. Make a stadium. The game grows with your hardware.**

## ICBM Mechanics

After the infrastructure is done, the next thing is to make the game fun!

[Author inspiration of deadly cross from playing maplestory](https://www.youtube.com/watch?v=rvdWpjRZVUQ&t=148s)
<video src="MapleStoryClip.mp4" controls width="100%">
  Your browser does not support the video tag.
</video>

As the author spent hefty time and heavily inspired by Maplestory and GregTech (Minecraft mod about real-life industrial processes), the author has been thinking about building a game out of that concept. The next feature: player controls a jet with its own maneuver mechanics. Player can shoot ICBMs with a cooldown to another player's local map through the physics transfer demonstrated in this Pong prototype.

Portals spawn chaotically, indicated by color for connected pairs, where ICBMs are transported from attacker to target dimension (inspired by modern Maplestory boss mechanics). The ICBM bounces indefinitely until it crosses another portal or is destroyed by the player.

If an ICBM is destroyed by another ICBM not originating from that space, it triggers a deadly cross beam (parallel and perpendicular from the destroyed ICBM's trajectory and center), posing danger and penalty to the player. If two ICBMs not originating from local space collide, they form 2 deadly crosses based on the collision direction – introducing chaotic dynamics where players choose between attack and defense. If a player is destroyed, all ICBMs originated by that player disappear until the last man stands.

However, based on the current minimal proof-of-concept code, it already occupies 2 tile spaces from Tiny Tapeout. Implementation is unlikely – the author believes this is enough to demonstrate the distributed computing concept.

## Beyond a Silly Game: The Future of Chip-to-Chip Communication

Distributed computing relies heavily on chip-to-chip communication. The current bottleneck for AI/data center chips is **power** and the **shoreline** – the physical edge where massive amounts of parallel data enter and exit the chip.

In this game, interconnect between chips is demonstrated through jumper wires between bidirectional pins on a PMOD socket. In real modern chips, they use tiny copper wires or optical transceivers to route data – but this has already reached its physical limit.

---

### Industry Landscape & Motivations

<img src="Co-Packaged Optics.jpg" width="100%" alt="Co-Packaging Optics Transition">

*Source: "Co-Packaged Optics for our Connected Future." YouTube, uploaded by [Microelectronics], 2024. [Video]. Available: https://www.youtube.com/watch?v=Xt-GY8Pkt6g*

<img src="Co-Packaged Optics2.webp" width="100%" alt="Co-Packaging Optics Roadmap">

*Source: Chang, Y.H. "Co-Packaged Optics (CPO) 2026-2036: Technologies, Market, and Forecasts." IDTechEx, 2025. [Report]. Available: https://www.idtechex.com/en/research-report/co-packaged-optics-cpo/1138*

---

### The Next Frontier: Sub-TeraHz Interconnect

To jump to the next generation of data transfer rates (sub-TeraHz frequencies), paths must be further shrunk, and new physics mechanisms must be implemented.

<img src="Copper vs Optics.webp" width="100%" alt="Copper vs Optics Comparison">

*Source: Blackburn, C. "The 400G-Per-Lane Inflection Point: Where Copper and Optical Meet in AI Infrastructure." Astera Labs, 2024. [White paper]. Available: https://www.asteralabs.com/the-400g-per-lane-inflection-point-where-copper-and-optical-meet-in-ai-infrastructure/*

**The copper problem:**
- Signal degrades through AC skin effect
- Severe resistive heating prevents further miniaturization
- Physically capped at 400G/lane

**The optical solution:**
If anyone wants to build the next generation of interconnect, photonics is not an option – it becomes a **necessity**.

<img src="Broadcom NPO.png" width="100%" alt="Broadcom VCSEL NPO Architecture">

*Source: Broadcom Inc. "Beyond the Copper Wall: Scaling AI Clusters with VCSEL-Based Near-Package Optics (NPO)." Broadcom Blog, 2024. Available: https://www.broadcom.com/blog/beyond-the-copper-wall-scaling-ai-clusters-with-vcsel-based-near-package-optics-npo*

The industry currently uses VCSELs (Vertical-Cavity Surface-Emitting Lasers) for optical transceivers – arrays of lasers and photodetectors mounted on a chip. However:

- Laser physics requires tight thermal management and suffers from stability issues
- Laser dead time, hard reliability limits, and short lifespan
- Single laser failure → entire optical channel lost → whole chip requires replacement
- Monochrome laser with binary On/Off limits parallelism in single bus waveguide
- Undeployable for next-generation sub-TeraHz data transfer

---

### The Author's Research

Current technological evolution is moving from:
- **Pluggable modules → ASIC → direct substrate integration (Co-Packaging Technology)**

<img src="Microring Resonator Optical Transceiver.png" width="100%" alt="Microring Resonator Optical Transceiver Design">

*Source: Saiham, D., Wu, D., & Rahman, S. "Leveraging photonic interconnects for scalable and efficient fully homomorphic encryption." arXiv preprint arXiv:2506.12962, Jun. 2025. DOI: 10.48550/arXiv.2506.12962. Available: https://arxiv.org/abs/2506.12962*

This evolution aims to solve power and bandwidth bottlenecks. The author is researching and proposing a solution using **nonlinear optical materials** for ultra-fast modulation through electro-opto-electro conversion via the **Pockels effect**, coupled with **athermal materials**.

With novel materials like **Thin Film Lithium Niobate (TFLN)** and **Barium Titanate Oxide (BTO)**, the author believes this design could overcome most hard limits of existing approaches. The fabrication capability for these materials is currently extremely limited, representing both a challenge and an opportunity.

The author argues that developing a vertically integrated **electronic-photonic integrated circuit (EPIC)** fab is a worthwhile investment in today's technology landscape, as these architectures gain increasing attention in both academia and industry.

| Task | Status |
|------|--------|
| Simulation and optimization of optical channel density for MRR array cascaded in a single bus waveguide with improved athermal ability (balancing thermal optic effects) | Stalled |
| CAD fabrication process in Onshape for 7nm CMOS FinFET technology | Stalled |
| DRAM development (co-developing while contributing to game development for [SuperSymmetry](https://susymodpack.substack.com/p/3-circuit-overhaul)) | Work in Progress |
| Complete circuit design flow for a proposed EPIC chip | Planned |
| Develop minimal viable layout schematics for MRR Photonics Stack on CMOS BEOL with active thermal control | Planned |
| [**2026 Chipathon**](https://sscs.ieee.org/technical-committees/tc-ose/sscs-pico-design-contest/) – Winning Chipathon with an open-source cleanroom particle detector | Current next task |

*The Chipathon is an open-source IC design contest hosted by the IEEE Solid-State Circuits Society (SSCS) under the PICO program. The 2026 theme is “Build It. Test It. Publish It.” Participants work in teams through a structured five-phase flow, from onboarding to tapeout, with the option to publish results. The contest is open to anyone worldwide, with mentorship provided. – [Source](https://sscs.ieee.org/technical-committees/tc-ose/sscs-pico-design-contest/)*

### This Project as Distributed Computing Proof-of-Concept

This silly Pong game is more than just a game. It demonstrates:

- **Chip-to-chip trust** – Two identical chips negotiating who is left and right
- **Fault tolerance** – One chip dies? The other keeps playing
- **Self-healing** – Reconnect and they rebuild the world automatically
- **Decentralized consensus** – No master, no slave. Just equals cooperating.

The same principles scale from two chips playing Pong to thousands of chips in an AI data center. The math changes. The concept stays the same.

---

### A Word from the Author

The author has been working on this project alone and has run into many life challenges. Nobody believed a "nobody" and also would be crazy enough to attempt for a fight for world-class semiconductor empire. So the author bit the bullet and tanked all the losses as personal fault.

This silly Pong game? It's a stupid prototype. A desperate attempt to prove that this could work. To convince people that one person who have nothing to do in life but with a dream and 100+ hours within a week can make something real.

**If you're interested – even just curious – I'd love to chat.**
Connect with me on [LinkedIn](https://www.linkedin.com/in/timllh/).
---

### References

1. Broadcom Inc. (2024). Beyond the Copper Wall: Scaling AI Clusters with VCSEL-Based Near-Package Optics (NPO). *Broadcom Blog*. https://www.broadcom.com/blog/beyond-the-copper-wall-scaling-ai-clusters-with-vcsel-based-near-package-optics-npo

2. Blackburn, C. (2024). The 400G-Per-Lane Inflection Point: Where Copper and Optical Meet in AI Infrastructure. *Astera Labs*. https://www.asteralabs.com/the-400g-per-lane-inflection-point-where-copper-and-optical-meet-in-ai-infrastructure/

3. Chang, Y.H. (2025). Co-Packaged Optics (CPO) 2026-2036: Technologies, Market, and Forecasts. *IDTechEx*. https://www.idtechex.com/en/research-report/co-packaged-optics-cpo/1138

4. Co-Packaged Optics for our Connected Future. (2024). YouTube. https://www.youtube.com/watch?v=Xt-GY8Pkt6g

5. Saiham, D., Wu, D., & Rahman, S. (2025). Leveraging photonic interconnects for scalable and efficient fully homomorphic encryption. *arXiv preprint arXiv:2506.12962*. https://arxiv.org/abs/2506.12962

### Why This Matters for Pong

This tiny Pong game – two chips passing a ball across jumper wires – is a **microcosm** of the same challenge facing the largest AI data centers. The same principles apply:

- Chip-to-chip trust
- Distributed consensus
- Bandwidth limits
- Fault tolerance

**What started as a game becomes a prototype for the future of computing.**

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
