import argparse
import xml.etree.ElementTree as ET

#length = 5, width = 6, collision radius = 0.5, visual radius = 1.0, starting location = (1,1)

world_file = "single-i.sdf"
output_file = "generated_snow.xml"

field_start_x = 1
field_start_y = 1
field_end_x = 6
field_end_y = 7

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Let it snow")
    parser.add_argument("CL", type=float, help="collision length")
    parser.add_argument("VL", type=float, help="visual length")
    parser.add_argument("CR", type=float, help="collision radius")
    parser.add_argument("VR", type=float, help="visual radius")
    args = parser.parse_args()

    root = ET.Element("sdf")
    root.set("version", "1.6")
    world = ET.SubElement(root, "world")
    world.set("name", "default")

    for x in range(field_start_x, field_end_x, 1):
        for y in range(field_start_y, field_end_y, 1):
            #setup stuff for making several snow pucks
            model = ET.SubElement(world, "model")
            model.set("name", "snowpart_" + str(x) + "-" + str(y))
            pose = ET.SubElement(model, "pose")
            pose.set("frame", "")
            pose.text = str(x) + " " + str(y) + " 0.01 -0 -0 -0"
            link = ET.SubElement(model, "link")
            link.set("name", "link")
            #collision
            collision = ET.SubElement(link, "collision")
            collision.set("name", "collision")
            cgeom = ET.SubElement(collision, "geometry")
            ccyl = ET.SubElement(cgeom, "cylinder")
            crad = ET.SubElement(ccyl, "radius")
            crad.text = str(args.CR)
            clen = ET.SubElement(ccyl, "length")
            clen.text = str(args.CL)
            #visual
            visual = ET.SubElement(link, "visual")
            visual.set("name", "visual")
            vgeom = ET.SubElement(visual, "geometry")
            vcyl = ET.SubElement(vgeom, "cylinder")
            vrad = ET.SubElement(vcyl, "radius")
            vrad.text = str(args.VR)
            vlen = ET.SubElement(vcyl, "length")
            vlen.text = str(args.CR)
            #
            self_collide = ET.SubElement(link, "self_collide")
            self_collide.text = "0"
            kinematic = ET.SubElement(link, "kinematic")
            kinematic.text = "0"

    tree = ET.ElementTree(root)
    tree.write(output_file)
