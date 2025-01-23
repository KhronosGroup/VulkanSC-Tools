# Copyright (c) 2025 The Khronos Group Inc.
# Copyright (c) 2025 RasterGrid Kft.
#
# SPDX-License-Identifier: Apache-2.0
#
# This script takes an image and converts it to PPM in C uint8_8 array format

import argparse
from PIL import Image
import os
import sys
import tempfile

def main(argv):
    parser = argparse.ArgumentParser(description='Convert an image to PPM in C uint8_t array format')
    parser.add_argument('input') # positional argument
    parser.add_argument('output') # positional argument
    args = parser.parse_args(argv)

    sc_logo = Image.open(args.input)

    input_base = os.path.basename(args.input)
    tmp_base = input_base.replace(os.path.realpath(input_base).split('.')[-1:][0], 'ppm')
    tmp = os.path.join(tempfile.gettempdir(), tmp_base)

    sc_logo.save(tmp)

    content = open(tmp, 'rb').read()
    new_content = []
    for byte in content:
        new_content.append(f"0x{byte:02X}")
    new_content = ', '.join(new_content)

    open(args.output, 'w').write(new_content)

if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))