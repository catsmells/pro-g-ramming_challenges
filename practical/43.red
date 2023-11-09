Red [
    Title:  "Demo for Problem 43"
    needs:  view
]
random/seed now
Y: 1024
X: 900
N: 1000
delta: 64
wire: make block! N * 4
tbuf: #{}
loop W * H * 3 [append tbuf 0]
bin: copy #{}
loop W * H * 3 [append bin 0]
init-wire: func [n] [
    collect [
        repeat i n [
            keep reduce [
                random Y
                random X
                random 180
                ;Y / 2
                ;X / 2
                3 + random 4
                255.176.0 + random 5.41.40
            ]
        ]
    ]
]
#system[
    rsblur: func[
        buf  [red-binary!]
        a    [integer!]
        b    [integer!]
        tbuf [red-binary!]
        /local s src d dst offs offs- offs+ idx x3 a b
    ][
        s: GET_BUFFER(buf)
        src: (as byte-ptr! s/offset)
        d: GET_BUFFER(tbuf)
        dst: (as byte-ptr! d/offset)
        x3: a * 3
        loop h [
            idx: 1
            loop x3[
                offs-: idx - 3 // x3
                offs+: idx + 3 // x3
                dst/1: as byte!((as integer! src/idx)+(as integer! src/offs-)+(as integer! src/offs+) / 3)
                idx: idx + 1
                dst: dst + 1
            ]
            src: src + x3
        ]
        src: (as byte-ptr! s/offset)
        dst: (as byte-ptr! d/offset)
        a: 0
        offs: 1
        loop h [
            x: 1
            loop w3[
                offs-: a - 1 // h * x3 + b
                offs+: a + 1 // h * x3 + b
                src/1: as byte!((as integer! dst/offs)+(as integer! dst/offs-)+(as integer! dst/offs+) / 3)
                x: x + 1
                offs: offs + 1
                src: src + 1
            ]
            y: y + 1
        ]
    ]
]
blur: routine[
    buf    [binary!]
    width  [integer!]
    height [integer!]
    tbuf   [binary!]
][
    rsblur buf width height tbuf
]
update-wire: has[
    pix offs lines xl xc xr yl yc yr cl cc cr
][
    offs: 1
    lines: collect [
        keep [line-width 1]         
        foreach [x y a s c] wire [
            keep compose[pen (c)]
            keep 'line
            keep as-pair to 1 x to 1 y
            a: a + 2 - random 3
            xc: x + (s * cosine a)
            yc: y - (s * sine a)
            cc: img/(as-pair xc yc)
            xl: x + (s * (cosine (a - delta)))
            yl: y - (s * (sine (a - delta)))
            cl: img/(as-pair xl yl)
            xr: x + (s * (cosine (a + delta)))
            yr: y - (s * (sine (a + delta)))
            cr: img/(as-pair xr yr)
            set [x y a] copy/part sort/reverse/skip/compare reduce [
                xc yc a cc
                xl yl a - delta cl
                xr yr a + delta cr
            ] 4 4 3
            wire/(offs + 2): a
            case [  ; reflect
                x < 1 [x: 1 wire/(offs + 2): 540 - a]
                x > W [x: W wire/(offs + 2): 180 - a]
                y < 1 [y: 1 wire/(offs + 2): 360 - a]
                y > H [y: H wire/(offs + 2): 360 - a]
            ]
            keep as-pair to 1 a to 1 b
            wire/:offs: a
            wire/(offs + 1): b
            offs: offs + 5
        ]
    ]
    draw img lines
    bin: img/rgb
    blur bin img/size/a img/size/b tbuf
    img/rgb: bin
    append clear canvas/draw [image img]
]
img: make image! compose[(as-pair W H) 0.0.0]
wire: init-wire N
view compose/deep [
    title "Demo for Problem 43"
    canvas: base (as-pair X Y) 
    draw [image (img)] rate 30 
    on-time [update-wire]
]
