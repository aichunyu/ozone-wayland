// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef OZONE_PLATFORM_GPU_PLATFORM_SUPPORT_HOST_H_
#define OZONE_PLATFORM_GPU_PLATFORM_SUPPORT_HOST_H_

#include <vector>

#include "ui/ozone/platform/drm/host/drm_gpu_platform_support_host.h"

namespace ui {

class ChannelObserver;

class OzoneGpuPlatformSupportHost : public GpuPlatformSupportHost,
                                    public IPC::Sender {
 public:
  OzoneGpuPlatformSupportHost();
  ~OzoneGpuPlatformSupportHost() override;

  void RegisterHandler(GpuPlatformSupportHost* handler);
  void UnregisterHandler(GpuPlatformSupportHost* handler);

  void AddChannelObserver(ChannelObserver* observer);
  void RemoveChannelObserver(ChannelObserver* observer);

  bool IsConnected();

  // GpuPlatformSupportHost:
  void OnChannelEstablished(
      int host_id,
      scoped_refptr<base::SingleThreadTaskRunner> send_runner,
      const base::Callback<void(IPC::Message*)>& send_callback) override;
  void OnChannelDestroyed(int host_id) override;

  // IPC::Listener:
  bool OnMessageReceived(const IPC::Message& message) override;

  // IPC::Sender:
  bool Send(IPC::Message* message) override;

 private:
  int host_id_ = -1;

  scoped_refptr<base::SingleThreadTaskRunner> send_runner_;
  base::Callback<void(IPC::Message*)> send_callback_;

  std::vector<GpuPlatformSupportHost*> handlers_;  // Not owned.
  base::ObserverList<ChannelObserver> channel_observers_;
};

}  // namespace ui

#endif  // UI_OZONE_GPU_DRM_GPU_PLATFORM_SUPPORT_HOST_H_