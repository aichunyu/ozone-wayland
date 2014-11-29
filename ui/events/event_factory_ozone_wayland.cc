// Copyright 2014 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ozone/ui/events/event_factory_ozone_wayland.h"
#include "base/bind.h"


namespace ui {

// static
EventFactoryOzoneWayland* EventFactoryOzoneWayland::impl_ = NULL;

EventFactoryOzoneWayland::EventFactoryOzoneWayland()
    : event_converter_(NULL),
      observer_(NULL),
      ime_observer_(NULL),
      output_observer_(NULL) {
  EventFactoryOzoneWayland::SetInstance(this);
}

EventFactoryOzoneWayland::~EventFactoryOzoneWayland() {
}

EventFactoryOzoneWayland* EventFactoryOzoneWayland::GetInstance() {
  CHECK(impl_) << "No EventFactoryOzoneWayland implementation set.";
  return impl_;
}

void EventFactoryOzoneWayland::SetInstance(EventFactoryOzoneWayland* impl) {
  CHECK(!impl_) << "Replacing set EventFactoryOzoneWayland implementation.";
  impl_ = impl;
}

void EventFactoryOzoneWayland::SetWindowChangeObserver(
    WindowChangeObserver* observer) {
  observer_ = observer;
}

void EventFactoryOzoneWayland::SetIMEChangeObserver(
    IMEChangeObserver* observer) {
  ime_observer_ = observer;
}

IMEChangeObserver*
EventFactoryOzoneWayland::GetIMEChangeObserver() const {
  return ime_observer_;
}

WindowChangeObserver*
EventFactoryOzoneWayland::GetWindowChangeObserver() const {
  return observer_;
}

void EventFactoryOzoneWayland::SetOutputChangeObserver(
    OutputChangeObserver* observer) {
  output_observer_ = observer;
}

OutputChangeObserver*
EventFactoryOzoneWayland::GetOutputChangeObserver() const {
  return output_observer_;
}

void EventFactoryOzoneWayland::SetEventConverterOzoneWayland(
    EventConverterOzoneWayland* converter) {
  event_converter_ = converter;
}

EventConverterOzoneWayland* EventFactoryOzoneWayland::EventConverter() const {
  CHECK(impl_) << "EventConverterOzoneWayland is not initialized yet.";
  return event_converter_;
}

}  // namespace ui
