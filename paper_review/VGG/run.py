import model as mk



layers = 19
# LRN = True     #working only for layers = 11
conv_1 = True  #working only for layers = 16

m = mk.make_model(layers, conv_1)

m.summary()


