# Control.Video.Api

`PiSubmarine.Control.Video.Api` defines the low-level video-control command vocabulary.

## Responsibility

`Command` represents the desired video state exposed to the rest of the control stack.

The command explicitly models:
- video disabled
- video enabled with a chosen stream profile
- autofocus or manual focus

`IController` defines the low-level controller contract that accepts a video target.

The API is intentionally transport-agnostic. It does not describe RTP, GStreamer, or remote negotiation.
