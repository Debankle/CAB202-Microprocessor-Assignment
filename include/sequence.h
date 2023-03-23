// n11028891, CAB202_2022se2, X31Y06

#include <stdint.h>
#include <avr/pgmspace.h>

// NOTE: As this header files declares variables, it should only be included
//       ONCE in your programme. If you need to make reference to the variables
//       declared below in multiple source files, use of the "extern" keyword is
//       recommended for this purpose.

char const TEST_BASE64[] PROGMEM = "kRSK";
uint8_t TEST_SCRAMBLED[3] = { 0x91, 0x14, 0x8A };
char const SEQUENCE[] PROGMEM = "\
sRSK1b7fI8UFF1OxotNxQqONCg0eJcqtKhcfc2dv+6nAZCLVBAq+lk/7JUwdF9W2\
S/Gf1mnT8Pp9ajF/KpFSgsV6F1O2rlM0RjN+bj/4rYJB/P7/o42aTXq9gkF8vl/z\
abGnQtsxiB1xKTKZXHdEb5EUxrr+sqMNlpJqeEajQaUtByVO63AbHPR68f0BkW63\
SyAziD4fHwomXlX2N55sextRuAX9bxFU5qp29gFc4ig3ir8DkU1ZPbjcoginj5sR\
8mqFoFHPBLWg7NMbMZ+AoUXqk+r4m3zBOp5F+RFB+Ftubz67WGfKO7jiELvyUfT6\
ZCLRAcIk/6fFEovWnysddVB5n7/d7CxNfB5nvnGJkSDysTZ8Lp9zqFLMc/lKUX5Q\
hDKNZRCZNyPT09csqAwO7iFBTbZZ4IrCqYhEJ0H5/TYRSLZUbp+HCCIAzwdBzztB\
Wj6ftZWWbfmg9mi0fK0Ko55PXR4XMAvZltjs0IQhyna7p5xOAU/7B0wmE9W2W/Ek\
FgZBKAgR3R2DyNrTIYXGKxHbJPnr4AqdhMeFVL6yToBpozszVbeTWSBT5BFTQ6Gf\
j3ggDFZypU/25xm6QVtPZ/taMcGjieLNvrQynUoIAMnBuOLvr6SYSDgTUfn7pYzG\
ZG3qcmazgh6PHNG0Xa0Kgh4P3DFEpVH0fb2Cxrze6CvJv9zu8KePnJEUjcU+mBNV\
8XvhK5bLvoBAp9BoM5rNvd0yHlCo02o1wWPtrVX2fOEskcu5B4DAZ7DYazablpRK\
Is5naGvpLxQKAt7vLMk4G45HeGNt7XVmtAVeqAtZd7hcKZeXEFf3IM+7BtxuMEd/\
ZO2q0rbbtoTCZuz2/KGMweOtjUV+OEN95XFkNRnQ7/T6+iIRU6pVcbuBm04nyDtB\
e75f9CVOIE975qxWLMm42+73IM+7BtxuMMc/RH1itgQCBtxuMEd/ZO0qkhYL3jCY\
y2YzQn6/BF1yPsBgt1gskUv5J5BIIxIJXCyWyDnaZzACC4ZZf2IrQaLRMxqNnc26\
2rJZdzgci0f/Ic0aGlIJT6TybmiU3e0KkharmBAogsLhq1arD9hsNxthc7rttdmA\
3OzGeGHscTvBOx6PmJEUjsWO2DP1uV/DpI73uYMd1emoUyqVkcs5R6BQLJRKJs5E\
aOuKj8RBtgShRvzdeGNObbWGxD1CJsxmNEV+uAPdtdkwn0wmFNU2nBHUbbWGxL2C\
Rnw+mJOVEYsZ1+h0PZ2SzjicSacP3DHE5fEkFYmYS6ZTcubzIk6niBtR83o9RSHM\
YTNF+f+jClotTaWOwD9D+iKREwqFmc+7hpxOpA/bNUSi1jQaihqNHY0aClotTaWO\
wD/DuoLBOx6PHFH0/X3i9iSSTng8GY8b1rTa6ioV0Wvpr1Sq0jYb1rTa6iqVl8u5\
BoBoJ5BgIpJh+fz++CPNPZ2STvj8+f+jihoN3W3q8qZTcmYzwr5fdGVusIcfVPUm\
lBXWbGlos9rtLZUWDNkwn8xmNEV+uAPdtdmwXywWDFlwv1yuUPeniBvRs1otTaWO\
wL8D2rJZd7hcKZcX0LeHGNM1QSNN/f0iE1Sq0DablpTK4q7XMMc/xD3C5iwWDFnw\
fzweiJsR0+r1IRPVsVtx43K5h0AgFwiExeEsEYuZF4jE5fGk1Wnoc7pd9fkgFwiE\
xeEsEQtZ9/h8OR/TMkajCtptbbUGhB3Sbuj0/X1iNkSiVnQ6mpLJPRwOhZ8T0jab\
lhSKwj6fEdW2XvEAlUlcO57rvAHcabcHWPMlSSdP/CHMYTPFOR/TsgaDmpJJ//x+\
uIMd1ekok8pl6XfnKMu5h8Dgd7jcaTdH+KMNXa2iQv5X5C1iIk4PSPuJj8bLqYpy\
eT/0OkKWi8bUqoryOJ+kFFYrzjgcCQdfdOUuENc3QP8jzrrdNpkwDwQiBlyOUPeH\
iBtxcrr9M5mQT6TSbmi0Xq2Kxr76NEXb+CPoOB13LMjk9fkgl8jkdTlAp1Aok8rl\
qdc3QH9jamq1gUN9ZTFEJRHU7fWm1DXG5C3K4i6XkBfXMMc/xL0ChhwOAN8zwj4f\
1DXG5C3K4q7XMMe/hJ2STXg8HY8v1rTu6iohUas93+zCfGHYcbsx2+5HYG/bLkiU\
Vam4RyIhUKrVsVvxo9LpL5TKYm63AF/zIk6nCNsxw2KxAwIBWy4X0DfHuANddTnA\
ZzCYy2Yzwr7ftIWeSPuhj0ajiZr5PZ0mjpj45/MRyOcvzLmAx2CwX6xWrAlYK5bL\
vgCAx+BwP5zO4C9L/iCQT6TSbmi0XS1Koo7HOMM9RSHMYbOFGQ/bNkSiVnQ6GtJp\
bzSaSnq9BYEciUd/5K0Kgp5P/KEMgcO9BQHc6XfnqIsZV6jU7fUmlJUWjxnQ6/T6\
+qJRdzodVinj4/LSJ5BjpVKCDgQChhwOAN+zAl6vDFlwv1wukJeXkJeXEFd3YG/r\
rojE5XFktdmwX6xWrAlYq1YrTng8GY+bFlSqUnY7xrxeqIsZVyiUTaUOAN+zAl6v\
jBlQr1QqElYrTvj8eT9D+qLRM5rNPR3S7qhULZUWj5kQC4RCJkym1LWGRP0ilhSK\
wj6fFNW2XPEkFQlYKxaLnhAIA4LBO57PvIGcSSfPvQFcL5e0ENcUwL8g2rL6N5jv\
YTNmfD9g+KJRc7rdNZkQj8TidmSy3jCYS6ZTcmazAt5v7ClIo1KpDwQChhyOQP+j\
CtrtrdU2HFH0/f0iFtTq8iYTUvZ7Zux2vIGcSSdPfGFsMZuRk8pl6fenCNuxg8Jh\
63a7hhwOgB/TsgYDWnI5R6DQ7fR6vwKBm06niBvRs1otTSXO5i9L/yAGD4RUJ0ww\
kpUmjJkgj0QSlpT64i4nUPeXjRvhsdpt7fUmlJUWDNmwX6xWrImYSyaTElarjhgM\
gUP9pVF0PZ0SDlisUSvJP5xOoI8bVnS62rJZ9/j8+X/jqgqFGY+blpRKIs5n6KsJ\
X6zW7KkIg0Ihy2azAt5vbGlos9rtrVX2/CHMYbMFWS/LvIDA4nA4m04nSPuhi8bj\
qgQFWaGLnh6IQyyRk8Tlqdk3wD9DemKxg0why2izgpBP/C9MoV1FYb21GoGrkhoK\
AlCvDNewXyyWzDnAZzCYSyYT0jYbVHS6X/LJJ5B4o9LZqlQaENZrbmi0XS3K4i6X\
EFd3YG/rLshktdmw3+x2vIEciUd/ZO0/khYeXvBtOx4a3DHRY7ERA4Eci0c1ZGMg\
MsipKkRvSSmFOE82ulHzogCHGFP1oVN14f0lSakPXP8klUn4e75fdOWu0DfHOMM9\
xeGs0eupj0Qil5TKZG4HwL+zGlwpz+ryfm6w3+J2PM88GQ9b9qTS7iiUTSXOYG9r\
7qbU7fsmlBtWrIeYSyiTElarjpjMYbMFWa+LnhA7hUwSSqhTcuhz4qDXMMk/RHNi\
tgSCRXy+XPMSSSl4/C97IZ3VkUu5J5CI43L5hsCgcTacyWnvrImYS6ZT8iaTElar\
Dthssduxg0Ihy+bzIk6niJuRk8plaTfHuIMd1Wnoc7rdNRnQb7Ta6qpV8Xtha7Zb\
duRyPkAgFwiERaGMwW3trVt2PM+82eErzjYcCQnftAXeaOupj8piNcricmpyHl5o\
k0rlicf/hB0SKkjk1mdos1QtTaWOQP8jSvr9JRFULZuWzDdAp97o83Q9Qa8MAg3F\
tdcoH4zeZG3y8iYL1zaDENTqcWYbwrD3tIs2CFVZ4/zRot7A8fR9Zb8EBYEcCQff\
tAVeKEv5p9BoM5pNfT1CJsxmtIWeSPuhCwaDmhIJ32w2GtE0nM36WvI553B4m84n\
6KtJ32K2XH9kNZeQz+ryfuDw//K++K1NXaPKQnB/RfNiEFoqElirjhgMAYMd1Wlo\
s9rtLZUWjBlQL5TK4q5X8CfPPME8mc+7BtxusAdf8SVOoo9c1jTdyjpa1elvk8qi\
KZcXUHdn6KuJn0wmFVV2ugGbaTeAOMP6BQEbKZfQk5dQ1LcHWP2liUn/pANaqopF\
+XHjqgQFWSFL/q7Q7/r6+iwJ0+rtIRPNsdspwGKpB4JB+/7/JE16OkKhi8Zjamo1\
wWPtrVX2/CHMYbOFmU9LZuxGvAFsKRdnc+efiJkQj8RiNsTiduRyvoBAIhCIwWJh\
w+IhY7IJ9/gsOJ/DFFZsTva7ebFEXPw+5v74ez4fV/smkJsmDFdAv1IekBnnsImv\
EtsGHd80HQ3aaup14fOlC4efEVUuPMHkWS+TPsC4d7gELJdP0jdHeGPtrVV2PMG8\
2W/rrggEBYEciUd/5K0Kgh6PHNG0XS3K4q5X8KcPWvGk1Gmo8/q9JZFUjUU+ugOd\
sNmw32K2XP+k1WdoMxqNncM6GlypD4pCJkImlBtWrIcYCwYDWnI5x2Cw3Gy22LFA\
BYFYCQcbdOVqkBeTNsd7RX3iduTyfmCw32y2XfEkE4koC4jzugyxm0CXiBVh9/TN\
pl/0/X3idmoyHl6o0+R1Yb2FGYEb1jqaSvR95X/k9fkgF4jEZTFEJRFUrdU2nJEU\
DQVeqIuZlEikUamoQKLxt9rtrdW2XPGk1Wno83o9xWFssdsxw2IxQ6LRMxoN3W3q\
8qZT8igT0rh9dupUvg4mh85GMxaqQq04XS3/YWCCBNGzghCPnJ+UTSXOYO+rjpjM\
4XPlKZcXUHfnqIuZl0gklUd4u9DvrIcYC4hDemyxBYJB+v4s5C2ZZ+4kYu+rDths\
MpWRl0QdyekXzjd4Ih4IA4zBu1AvzDnA53A4m06niJWRE4RF+XHjqgQFWSHLPk6g\
VygUjcu+WP0lSamPHFH0/X3iduRyPkCgUSgUj8UOHlP1oFNE5/OlCYefFFV2uAHc\
ajf3uAPttVnA/3wOmpMl1+upicT3duRnvoBVp9D98/poZbE/BYGnyWdU7KmzRaJq\
9Xo9R6EsgcMdxWFMMZsxVyS1FwXZM5bq4X3DKZkxUPkBSvWHjsjTLsrVKpcX0LmH\
GN01we2tDQWb6CuMP5wLoI/ekJSP467XMUl/YmM6sQhT3jyZl8bkcbkAhE5lF4aB\
5X8htVc1vNyrdGfvrAlYrVYrzLgML5eXENc3wrGDH9w5b7oKKkR1Salf3jEUo1F0\
Ox1KLsj89fk4l8h8tFfo+XI+mJ2VEQtZd7hcKZeXkBfXMEd/ZG1qsgYDWvJ5YjCY\
yebIJ04cyruBnk4nSvWbjkaZCNpt7fWmUfUmlhXuaemQUapVcTtB+/5/5C3K4q7X\
MMe/hB3Sbuh0vV1yvYDA43CDWK5s9CfPP8E8nc98xjzZS3smbzablhQKgh4P3D/E\
Z78EAA+K63exrQVZ9/Z8uVFz467XNsf6BN333j7dS6gWcmj2At6qLEc9u1BqTHel\
9/jpeT/WOkIhS6jTsghj3LJZ9van/3+4q4pFeTFD/KxRcjSFlUdgvdB37SdII5xJ\
//L+eG3tqNu23r9XBQ8PLBcEcud8yblThUCgV6jU7XvmdOuu0LeHHNO1gkOuJZHH\
yeV9E1f3oIEb1rpaqgoF2u8rSvi0ej8LfmyxgEwhTyjbEtgjbWj8Wa0KAl6vDFnw\
/3y+2jNFfD/zOsLRq9Zb7qjk7/UWEtU2mhFxrdUTHVFRO52SzjgcCYcfVPWGVHXG\
9KWuwL8jWvL5p1AoE4oTebED2rzZMZjMYD0f///5C9RtbbuGwr0CB9y79ieaPcG8\
2W/rrgYEgE/8ezFremwZw+zZo1yBikQKFFQqElYrzjgcCYmfEFv2/6/cxeN9TqvJ\
RH+kLEqlDYdXVPvu17vOwLPBxbKdbOX6jMqx8qpSrgYEBQ/cabmHmJ0VUSVJfzwe\
CFvxoVKpCoRVpgyRRv01EFSqVHaehhwrgZ+2lBbInhDLQiLSlcpl6fcnSPuhi0Zh\
yro/dbmAR6CQb7QOqgpR2eGrCNZssNXWhcIG6naRBtLE9qmlnR9MrVVuOsEkGAG8\
tgplANwJMUd/ZO2q0jYb07TaaOox5HMha7cH3bMFWy8j+yB4CQSCxTxeCNtxx2Lx\
AAKxm87XqAtpdziszeefipmQS6R6rgisRqGkRSMKfb3FRfy5fGPdrVVGP0FMPR+R\
MsahqYqHPx/TtwYr2jIxVaj8aDVGpI0aCtptbTtGpI2ayjqdlMm43W7ngBGDMkZz\
yrQNdDeQ4X64225/wD8LemKxA4LBO54LfOGsUSvJv9zu9qePHVFEvV3C/iCgT6Ti\
6KhkrFUSuoF4CIcf1DXGZO0qElYrzjicyWfvrAlYr1arjRjIxeNpTiXOYO+rDtjs\
9XthaLaLtgTSxryO6CWZv1J+kJfHEFcn4K9bXfCo/352R32rcmSy3jCYyWazB15r\
Tvnk0uhEvV3C/iCgT6TibOhEOx3S6CikTSV+oI+rlpR6o473PsOahUFbud8Uwj44\
1TVhog1aqor1OR/jMsZjamo1wWNt63XmdeVpFlcwYW/rLsjk8/kglsjEdTlgJ5Do\
Yzw50ebUfDNCJkym0bWGRv1ClhRqB96PLslxm07ujRuYMRoNXS1KJs5na+vhi8Qq\
NcRitgQChhwOgB9Tcmazgp5P/y/M5f3CisnYgJPFzbgLrVkg4y8ceu5nPxKZQ/+0\
DFotyGVLsAn6tIs7iJu0l8rAKpeXEFd35C9L/a4aqtQgsAYD2rJZd7hcKZcX0DfH\
PUP9p1Gkez2S5yyWzLkAB4BAodBosto47fVzFFUjPEGp+f92Svoo5fFxlsltn04n\
SPuhCwgDWny5gsBgtVZskUs553B4Gw7HGNO1AQPdNRfD7vrpfOyxo9wp73p6mhLJ\
nExmkBVWLEn4fzAfV/u11DvV4S3Z4CDflpffEdc3wLED2rzZt9bE8fUJS6h78Cg7\
17hbdmqyXf54PxDfmJFEDgVeKEv5p1CoViSVk0WqIZ4bIhwJ2ex2vQ9sKZenENcH\
wb+zHNJp7/r6euzxo1ypDIpCogK2RPMSFlqaUvZLY2yGXvEklcm43W43Qf9rS3r1\
AwFcqNc3xr/TmJKZuVyuVnenKMv5hcAgslgXEgticzgcCQdf9KUOgJ+Tl5ZLfOAr\
OZyVYW9rbmg0nU36euJx43y5Bg6AQS6qzeRIuw5KBI6KYb7YbrgR9qSY7SbeSauO\
wDFD+iIR0+r1JJOVk0tJ5/BIu16fDFlAP5JrIUFeYGIOHlFMOB1SLMhksNn1XyxT\
D9l1G4x+pA1irgo92u8rzrhcqVd34K+LnhCIwmJ6RSIRUypQUCsM+Xy+WHPlqdc3\
QH/jqQSFncGTBtJGsAf3tAV2LUtRZTCYy+Zz4i6XENc3wD9DfGIxwuI6YbIScjic\
SSdP/K+MwW3trdU2nBFULRVWLMm42+53Y+8rSvisfD8TeGKxhUKhCgZDWHz5Ag6A\
x24wH4LGZG1qMkijCtRtbbUGBF1yvoDA53AgG47fOkPloFGU/f1CFtSy96aLMMZj\
6qpVcbWBHQCHmZ21kUVZZzA4i0YDTPpd5HHkdrkAA4AVp9C9c7QIdbfVR6AFLxRf\
At5v7KmIQ6JR8nq9g0Gvf7/QmBJTWSwWjBlQL5RKIkCniJWRk0QlSaePnJGUzeWu\
0DdHeOOtiMU+GlO1IROVMRuRNxTNHgNaqgoFWa8L3j6Yy2gzQnA/RP0ilpRKoI7H\
PcN1RSGE4XNl6fenCFvxI5LJORwOg59TV3a7hhyOwTFD/KxBczQN1ec4EIrVPR/T\
sgYDWPL5IpCPZjJe1eh0PRNSrgYEBY8cCYefFNW2XHHk9Xlgt9js9/uhikaLippl\
/X3Kc+TafOBwv1Ku0DlH+K2NHY0aClqtDYUeiBvRs9ptazVGpY24Svpf5fGGUKcq\
gcxh63i7hpJOoIEbVvr6+iIR02S1gc09xmHsdbvKHYAMee2tDYsejZURUaT+sVXa\
o9xC7fp6P8wr7vgxZGK2XnHk8HnId7b0aTnvvAN19nnL9/jX+X/IrAouWC9LfuDw\
fzyezbsBXq4U9qcPWXGg9XlgNxiMQaONnU36emIxw2Kxg0IhSyaTEtbrrggEBQFc\
KRdX8KePHNE0nUN6uozBu14vzDnAZzCYy+Zz4i4XUnfnLct5QqAQLZRKoo5H+KMN\
Wi3K5S6XF9c3R39jbWq1hsM9QqGMRiNN+v2i0TSaTfp9YrEEgsG83u8rSXi83u+r\
CVgsFgtZ8Ph8Pp8T1TYb0TQajRqNGg3abWq1BoMd0mloNBoN2m1qNcbjrYrFvl9z\
5S4XV/cnT/shTCYTVXa7Adxut4efk5UWC9mwWKxWK0l4PJ5P+6EMhkP9otG0";